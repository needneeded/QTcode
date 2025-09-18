#include "videowindow.h"
#include "ui_videowindow.h"
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QFileInfo>
#include <QFile>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QKeyEvent>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

VideoWindow::VideoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    ui->btn_mode->setProperty("mode","pause");
    this->player = new QMediaPlayer();
    this->vWid = new QVideoWidget();
    this->playlist = new QMediaPlaylist(this->player);
    this->player->setPlaylist(this->playlist);
    this->player->setVideoOutput(this->vWid);
    this->player->setVolume(50);
    ui->playbackSpeed->setCurrentIndex(this->rate);
    ui->verticalLayout->addWidget(this->vWid);
    //默认播放模式为顺序播放
    this->playlist->setPlaybackMode(QMediaPlaylist::Loop);
    // 1. 添加 SQLite 数据库连接（只执行一次）
    this->db = QSqlDatabase::addDatabase("QSQLITE","sqlite");
    this->db.setDatabaseName("D:/SQLite/file.db"); // 数据库文件名
    if (!this->db.open()) {
        qDebug() << "无法打开数据库：" << this->db.lastError();
        return;
    }
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &VideoWindow::videoIndexChang);
    // 安装事件过滤器到视频窗口，处理双击
    vWid->installEventFilter(this);
    // 标记初始状态
    isFullscreen = false;
    fullscreenWidget = nullptr;
    loadHistory();
}

VideoWindow::~VideoWindow()
{
    delete ui;
}
//事件过滤器
bool VideoWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == vWid && event->type() == QEvent::MouseButtonDblClick) {
        // 双击视频窗口切换全屏
        on_btn_fullScreen_clicked();
        return true;
    } else if (obj == fullscreenWidget && event->type() == QEvent::KeyPress) {
        // ESC键退出全屏
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            on_btn_fullScreen_clicked();
            return true;
        }
    }
    return QObject::eventFilter(obj, event);
}

void VideoWindow::onlineInit()
{
    QEventLoop loop;
    QNetworkAccessManager manager;
    // 发起 GET 请求
    QUrl url("http://localhost/video/");
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError)
    {
        QString html = reply->readAll();

        // 正则表达式匹配所有 .mp3 文件链接
        QRegularExpression re("<a href=\"([^\"]+\\.mp4)\">");
        QRegularExpressionMatchIterator it = re.globalMatch(html);
        this->playlist->clear();
        while (it.hasNext())
        {
            QRegularExpressionMatch match = it.next();
            QString fileName = match.captured(1); // 提取文件名
            QString fullUrl = "http://localhost/video/" + fileName;

            // 添加进播放列表
            this->playlist->addMedia(QMediaContent(QUrl(fullUrl)));
//            qDebug() << "添加视频：" << fullUrl;

            // 创建列表项并设置显示文本
            QListWidgetItem *item = new QListWidgetItem(fileName);

            // 保存文件路径到列表项的用户数据中
            item->setData(Qt::UserRole, fullUrl);

            // 添加到界面显示
            ui->onlineList->addItem(item);


        }
        ui->onlineList->setCurrentRow(0);
        ui->onlineList->show();
        if (this->playlist->mediaCount() > 0) {
            qDebug() << "共加载" << this->playlist->mediaCount() << "个视频";
            this->player->setPlaylist(this->playlist);
            this->playlist->setCurrentIndex(0);

        } else {
            qDebug() << "没有找到任何 MP4 文件";
        }

    } else {
        qDebug() << "网络请求失败：" << reply->errorString();
    }

    reply->deleteLater();
}

void VideoWindow::insertData(QString name, QString path)
{

    // 使用 INSERT OR IGNORE 插入数据
    QString insertSql = "INSERT OR IGNORE INTO video_history(video_name, video_path) VALUES (?, ?)";
    QSqlQuery insert(this->db);
    insert.prepare(insertSql);
    insert.addBindValue(name);
    insert.addBindValue(path);

    if (!insert.exec()) {
        qDebug() << "插入失败：" << insert.lastError().text();
        qDebug() << "执行的 SQL：" << insert.executedQuery();
    } else {
        qDebug() << "插入完成（如果记录已存在则被忽略）：" << name << "-" << path;
    }

    insert.finish();

}

void VideoWindow::loadHistory()
{
    QSqlQuery query(this->db);
        QString sql = "SELECT video_name, video_path FROM video_history";

        if (!query.exec(sql)) {
            qDebug() << "查询失败：" << query.lastError().text();
            return;
        }

        while (query.next()) {
            // 获取每个字段的值
            QString name = query.value(0).toString(); // 第一列 music_name
            QString path = query.value(1).toString(); // 第二列 music_path



            // 可选：将结果显示到 QListWidget 上
            QListWidgetItem* item = new QListWidgetItem(name);
            ui->localList->addItem(item);
            // 添加到播放列表
            this->playlist->addMedia(QMediaContent(QUrl::fromLocalFile(path)));

        }
        ui->localList->setCurrentRow(0);
        ui->localList->show();

        if (!this->playlist->isEmpty()) {
                this->playlist->setCurrentIndex(0); // 默认播放第一首
            }

}

void VideoWindow::videoIndexChang()
{
    if(ui->tabWidget->currentIndex()==0){
        ui->localList->setCurrentRow(this->playlist->currentIndex());
    }
    else{
        ui->onlineList->setCurrentRow(this->playlist->currentIndex());
    }

}

void VideoWindow::on_btn_exit_clicked()
{
    this->parentWidget()->show();
    this->hide();
}

void VideoWindow::on_btn_loadFile_clicked()
{
    QString defaultPath = "D:/Qt/qtCode/resource/video"; // 默认打开用户目录
    QString filter = "MP4 视频 (*.mp4)";
    // 弹出文件对话框，允许选择多个文件
    QStringList fileUrls = QFileDialog::getOpenFileNames(
                this,
                "选择 MP4 视频",
                defaultPath,
                filter);

    for (int i = 0; i < fileUrls.size(); ++i) {
        QFileInfo info(fileUrls[i]);
        QString fileName = info.fileName();
        QString filePath = fileUrls[i];
        insertData(fileName,filePath);
        QListWidgetItem *item = new QListWidgetItem(fileName);
        item->setData(Qt::UserRole, filePath);
        ui->localList->addItem(item);
    }

    if (!fileUrls.isEmpty()) {
        // 设置视频输出控件（必须！）
        // 确保你有一个 QVideoWidget 或 QGraphicsVideoItem
        QString firstFilePath = fileUrls[0];
        player->setMedia(QUrl::fromLocalFile(firstFilePath));
        ui->localList->setCurrentRow(0);
        ui->localList->show();

        if (!this->playlist->isEmpty()) {
            this->playlist->setCurrentIndex(0);
        }
    }
}

void VideoWindow::on_btn_mode_clicked()
{
    QString mode = ui->btn_mode->property("mode").toString();
//    qDebug()<< mode;
    mode = (mode == "play") ? "pause" : "play";


    ui->btn_mode->setProperty("mode", mode);
    ui->btn_mode->style()->unpolish(ui->btn_mode);
    ui->btn_mode->style()->polish(ui->btn_mode);
    ui->btn_mode->update();
//    qDebug()<<ui->btn_mode->property("mode").toString();;

    (mode == "play") ? this->player->play() : this->player->pause();
}

void VideoWindow::on_btn_pre_clicked()
{
    this->playlist->previous();
}

void VideoWindow::on_btn_next_clicked()
{
    this->playlist->next();
}

void VideoWindow::on_voiceSlider_valueChanged(int value)
{
    this->player->setVolume(value);
}

void VideoWindow::on_btn_fullScreen_clicked()
{

    if (isFullscreen) {
            // 退出全屏模式
            // 将视频部件从全屏窗口移回原始布局
            fullscreenWidget->layout()->removeWidget(vWid);
            originalLayout->addWidget(vWid);

            // 恢复全屏窗口
            fullscreenWidget->hide();
            delete fullscreenWidget;
            fullscreenWidget = nullptr;

        } else {

            // 保存原始布局信息
            originalParent = vWid->parentWidget();
            originalLayout = qobject_cast<QVBoxLayout*>(vWid->parentWidget()->layout());

            originalLayout->setContentsMargins(0, 0, 0, 0); // 清除内边距
            originalLayout->setSpacing(0);                 // 控件间距设为 0
            // 从原始布局中移除视频部件
            originalLayout->removeWidget(vWid);

            // 创建全屏窗口
            fullscreenWidget = new QWidget(nullptr);
            fullscreenWidget->setWindowFlags(Qt::FramelessWindowHint);
            fullscreenWidget->setStyleSheet("background-color: black;"); // 设置背景为黑色，避免白边

            fullscreenWidget->setLayout(new QVBoxLayout);
            fullscreenWidget->layout()->addWidget(vWid);
            vWid->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            vWid->setMinimumSize(0, 0); // 确保最小尺寸不限制扩展

            // 安装事件过滤器，处理ESC键
            fullscreenWidget->installEventFilter(this);

            // 显示全屏窗口
            fullscreenWidget->showFullScreen();
        }

        isFullscreen = !isFullscreen;
}

void VideoWindow::on_localList_itemDoubleClicked(QListWidgetItem *item)
{
    // 1. 获取双击项的文件路径（假设已将路径存储在UserRole中）
    int index = ui->localList->row(item);
    if (index!=this->playlist->currentIndex()){
        ui->btn_mode->setProperty("mode","play");
    }
    // 3. 更新播放
    this->playlist->setCurrentIndex(index);
    this->player->play();


    for (int i = 0; i < ui->localList->count(); ++i) {
        ui->localList->item(i)->setBackground(Qt::white);
    }
    item->setBackground(QColor(220, 230, 255)); // 浅蓝色背景
    on_btn_mode_clicked();
}

void VideoWindow::on_tabWidget_currentChanged(int index)
{

    this->playlist->clear();
    if(ui->tabWidget->currentIndex()==0){
        ui->localList->clear();
        loadHistory();
    }
    else{
        ui->onlineList->clear();
        onlineInit();
    }
}

void VideoWindow::on_onlineList_itemDoubleClicked(QListWidgetItem *item)
{
    // 1. 获取双击项的文件路径（假设已将路径存储在UserRole中）
    int index = ui->onlineList->row(item);
    if (index!=this->playlist->currentIndex()){
        ui->btn_mode->setProperty("mode","play");
    }
    // 3. 更新播放
    this->playlist->setCurrentIndex(index);
    this->player->play();


    for (int i = 0; i < ui->onlineList->count(); ++i) {
        ui->onlineList->item(i)->setBackground(Qt::white);
    }
    item->setBackground(QColor(220, 230, 255)); // 浅蓝色背景

}

void VideoWindow::on_playbackSpeed_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            this->rate = 0.5;
            break;
        case 1:
            this->rate = 1;
            break;
        case 2:
            this->rate = 1.5;
            break;
        case 3:
            this->rate = 2;
            break;
    }
    this->player->setPlaybackRate(this->rate);
}
