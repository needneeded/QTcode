#include "musicwindow.h"
#include "ui_musicwindow.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QStyle>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>
#include <QStringList>
#include <QNetworkReply>

MusicWindow::MusicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setStyleSheet("background-color:transparent");
    ui->btn_play->setProperty("mode","play");
    this->player = new QMediaPlayer(this);
    this->playlist = new QMediaPlaylist(player);
    this->lyricList = new QVector<QLabel*>;
    this->lyricList->append(ui->lb_1);
    this->lyricList->append(ui->lb_2);
    this->lyricList->append(ui->lb_3);
    this->lyricList->append(ui->lb_4);
    this->lyricList->append(ui->lb_5);
    this->lyricList->append(ui->lb_6);
    this->lyricList->append(ui->lb_7);
    this->keys = new QStringList();
    this->value = new QStringList();
    this->player->setPlaylist(this->playlist);
    this->player->setVolume(50);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::songIndexChang);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::olineIndexChang);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::lrcGet);
    connect(ui->voice_slider,&QSlider::valueChanged,this,&MusicWindow::voiceChange);
    on_btn_mode_clicked();
    // 连接播放器信号
    connect(this->player, &QMediaPlayer::positionChanged, this, &MusicWindow::onPositionChanged);
    connect(this->player, &QMediaPlayer::positionChanged, this, &MusicWindow::lrcDisplay);
    //进度条拖动事件
    connect(ui->music_slider, &QSlider::sliderPressed, this, &MusicWindow::onSliderPressed);
    connect(ui->music_slider, &QSlider::sliderReleased, this, &MusicWindow::onSliderReleased);
    // 1. 添加 SQLite 数据库连接（只执行一次）
    this->db = QSqlDatabase::addDatabase("QSQLITE","music_sqlite");
    this->db.setDatabaseName("D:/SQLite/file.db"); // 数据库文件名
    if (!this->db.open()) {
        qDebug() << "无法打开数据库：" << this->db.lastError();
        return;
    }
    selectHistory();
    timeRender();
    lrcGet();
    lrcDisplay();
}
//历史记录存储
void MusicWindow::insertData(QString name, QString path)
{
    // 使用 INSERT OR IGNORE 插入数据
    QString insertSql = "INSERT OR IGNORE INTO music_history(music_name, music_path) VALUES (?, ?)";
    QSqlQuery insert(this->db);
    insert.prepare(insertSql);
    insert.addBindValue(name);
    insert.addBindValue(path);
    if (!insert.exec()) {
        qDebug() << "插入失败：" << insert.lastError().text();
        qDebug() << "执行的 SQL：" << insert.executedQuery();
    } else {
//        qDebug() << "插入完成（如果记录已存在则被忽略）：" << name << "-" << path;
    }
    insert.finish();

}
//检索历史记录
void MusicWindow::selectHistory()
{
    QSqlQuery query(this->db);
        QString sql = "SELECT music_name, music_path FROM music_history";
        if (!query.exec(sql)) {
            qDebug() << "查询失败：" << query.lastError().text();
            return;
        }
        while (query.next()) {
            // 获取每个字段的值
            QString name = query.value(0).toString(); // 第一列 music_name
            QString path = query.value(1).toString(); // 第二列 music_path
            // 将结果显示到 QListWidget 上
            QListWidgetItem* item = new QListWidgetItem(name);
            ui->songList->addItem(item);
            // 添加到播放列表
            this->playlist->addMedia(QMediaContent(QUrl::fromLocalFile(path)));
        }
        ui->songList->setCurrentRow(0);
        ui->songList->show();
        if (!this->playlist->isEmpty()) {
                this->playlist->setCurrentIndex(0); // 默认播放第一首
            }
        query.finish();
}
//播放时间显示
void MusicWindow::timeRender()
{
    qint64 d = this->player->duration();
    qint64 p = this->player->position();
    int min_p=p/60000,min_d=d/60000,sec_p=(p/1000)%60,sec_d=(d/1000)%60;
    this->time_pos = QString("%1:%2")
            .arg(min_p, 2, 10, QChar('0'))     // 2位宽，十进制，补0
            .arg(sec_p, 2, 10, QChar('0'));
    QString time_dur = QString("%1:%2")
            .arg(min_d, 2, 10, QChar('0'))     // 2位宽，十进制，补0
            .arg(sec_d, 2, 10, QChar('0'));
    QString time = QString("%1/%2").arg(this->time_pos).arg(time_dur);
    ui->lb_time->setText(time);
    ui->lb_time->style()->unpolish(ui->lb_time);
    ui->lb_time->style()->polish(ui->lb_time);
    ui->lb_time->update();
}
//歌词获取
void MusicWindow::lrcGet()
{
    this->value->clear();
    this->keys->clear();
    QListWidgetItem *item;
    QString lrcPath = "D:/Qt/qtCode/resource/music_images/%1";
    if(ui->tabWidget->currentIndex()==0){
        item = ui->songList->currentItem();
    }else{
        item = ui->onlienList->currentItem();
    }
    QString songName = item->text();
    ui->songName->setText(songName);
    songName.replace(".mp3",".lrc");
    lrcPath = lrcPath.arg(songName);
//    qDebug()<<lrcPath;
    // 定义一个 QStringList 来保存每一行歌词文本
    QString line;
    QFile file(lrcPath); // lrcPath 是 QString 类型的歌词文件路径
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        while (!stream.atEnd())
        {
            line = stream.readLine(); // 读取一行歌词
            QString current = line.mid(1,5),word = line.split("]")[1];
            this->keys->append(current);
            this->value->append(word);

        }
        file.close();
        lrcDisplay();
    }
    else
    {
        qDebug() << "无法打开歌词文件：" << lrcPath;
        lrcDefault();
    }
}
//歌词展示
void MusicWindow::lrcDisplay()
{
//    qDebug()<<this->time_pos;
    if(this->keys->contains(this->time_pos))
    {
        int index = this->keys->indexOf(this->time_pos);
        int current = 0;
        if(index+1 > this->keys->length()-6)
        {
            current = index;
            index = this->keys->length()-7;
        }
        for (int i=0;i<this->lyricList->size();i++) {
//            qDebug()<<this->lyricList->size();
            (*this->lyricList)[i]->setText(this->value->value(index+i));
            if(i==0&&current==0){
                QLabel *label = (*this->lyricList)[i];
                // 设置样式：加粗 + 粉色背景 + 字号变大
                label->setStyleSheet(
                    "font-weight: bold;"
                    "font-size: 30px;"
                );
            }
            else if(current!=0){
                (*this->lyricList)[i]->setStyleSheet("");
                QLabel *label = (*this->lyricList)[current-index];
                // 设置样式：加粗 + 粉色背景 + 字号变大
                label->setStyleSheet(
                    "font-weight: bold;"
                    "font-size: 30px;"
                            );
            }
        }
    }
}
//拖动进度条更新歌词进度
void MusicWindow::lrcUpdateForSlide(){
    qint64 currentPos = this->player->position();
    qDebug() << "Current position: " << currentPos;
    for (int i = 0; i < this->keys->size() - 1; i++) {
        QString timeStr = this->keys->at(i);
        QStringList parts = timeStr.split(":");
        if (parts.size() == 2) {
            qint64 min = parts[0].toLongLong();
            qint64 sec = parts[1].toLongLong();
            qint64 timeMs = min * 60000 + sec * 1000;
            qDebug() << "Time at index " << i << ": " << timeMs;

            QString nextTimeStr = this->keys->at(i + 1);
            QStringList nextParts = nextTimeStr.split(":");
            if (nextParts.size() == 2) {
                qint64 nextMin = nextParts[0].toLongLong();
                qint64 nextSec = nextParts[1].toLongLong();
                qint64 nextTimeMs = nextMin * 60000 + nextSec * 1000;
                qDebug() << "Next time at index " << i + 1 << ": " << nextTimeMs;

                if (currentPos >= timeMs && currentPos < nextTimeMs) {
                    qDebug() << "Found matching lyric at index " << i;
                    int current = 0;
                    if (i + 1 > this->keys->length() - 6) {
                        current = i;
                        i = this->keys->length() - 7;
                    }
                    for (int j = 0; j < this->lyricList->size(); j++) {
                        (*this->lyricList)[j]->setText(this->value->value(j + i));
                        if (j == 0 && current == 0) {
                            QLabel *label = (*this->lyricList)[j];
                            // 设置样式：加粗 + 粉色背景 + 字号变大
                            label->setStyleSheet(
                                        "font-weight: bold;"
                                        "font-size: 30px;"
                                        );
                        } else if (current != 0) {
                            (*this->lyricList)[j]->setStyleSheet("");
                            QLabel *label = (*this->lyricList)[current - i];
                            // 设置样式：加粗 + 粉色背景 + 字号变大
                            label->setStyleSheet(
                                        "font-weight: bold;"
                                        "font-size: 30px;"
                                        );
                        }
                    }
                    break;
                }
            }
        }
    }
}
//析构
MusicWindow::~MusicWindow()
{
    this->db.close();
    delete ui;
}
//本地歌曲下标变化-槽
void MusicWindow::songIndexChang()
{
    ui->songList->setCurrentRow(this->playlist->currentIndex());
    if(this->playlist->currentIndex()==-1){
        on_btn_play_clicked();
        this->playlist->setCurrentIndex(0);
    }
}
//在线歌曲下标变化-槽
void MusicWindow::olineIndexChang()
{
    ui->onlienList->setCurrentRow(this->playlist->currentIndex());
    if(this->playlist->currentIndex()==-1){
        on_btn_play_clicked();
        this->playlist->setCurrentIndex(0);
    }
}
//音量变化-槽
void MusicWindow::voiceChange()
{
    this->player->setVolume(ui->voice_slider->value());
}
//默认歌词展示
void MusicWindow::lrcDefault()
{
    this->keys->clear();
    this->value->clear();
    QListWidgetItem *item ;
    if(ui->tabWidget->currentIndex()==1){
       item = ui->onlienList->currentItem();
    }
    else{
        item = ui->songList->currentItem();
    }
    QString songName = item->text();
    ui->songName->setText(songName);
    for (int i=0;i<this->lyricList->size();i++) {
        (*this->lyricList)[i]->setText("");
        if(i==0){
            (*this->lyricList)[i]->setText("暂无更多歌词");
            QLabel *label = (*this->lyricList)[i];
            // 设置样式：加粗 + 粉色背景 + 字号变大
            label->setStyleSheet(
                "font-weight: bold;"
                "font-size: 30px;"
            );
        }

    }
}
//返回-槽
void MusicWindow::on_btn_back_clicked()
{
    this->parentWidget()->show();
    this->hide();
}
//加载在线音乐
void MusicWindow::loadOnlieMusic()
{
    QEventLoop loop;
    QNetworkAccessManager manager;
    // 发起 GET 请求
    QUrl url("http://localhost/audio/");
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        QString html = reply->readAll();
        // 正则表达式匹配所有 .mp3 文件链接
        QRegularExpression re("<a href=\"([^\"]+\\.mp3)\">");
        QRegularExpressionMatchIterator it = re.globalMatch(html);
        this->playlist->clear();
        while (it.hasNext())
        {
            QRegularExpressionMatch match = it.next();
            QString fileName = match.captured(1); // 提取文件名，如 "song.mp3"
            QString fullUrl = "http://localhost/audio/" + fileName;
            // 添加进播放列表
            this->playlist->addMedia(QMediaContent(QUrl(fullUrl)));
//            qDebug() << "添加歌曲：" << fullUrl;
            // 创建列表项并设置显示文本
            QListWidgetItem *item = new QListWidgetItem(fileName);
            // 保存文件路径到列表项的用户数据中
            item->setData(Qt::UserRole, fullUrl);
            // 添加到界面显示
            ui->onlienList->addItem(item);
        }
        ui->onlienList->setCurrentRow(0);
        ui->onlienList->show();
        if (this->playlist->mediaCount() > 0) {
            qDebug() << "共加载" << this->playlist->mediaCount() << "首歌";
            this->player->setPlaylist(this->playlist);
            this->playlist->setCurrentIndex(0);
        } else {
            qDebug() << "没有找到任何 MP3 文件";
        }

    } else {
        qDebug() << "网络请求失败：" << reply->errorString();
    }
    reply->deleteLater();
}
//加载本地音乐
void MusicWindow::on_btn_loadFile_clicked()
{
    QString defaultPath = "D:/Qt/qtCode/resource/music_images"; // 默认打开用户目录
    QString filter = "MP3 音乐 (*.mp3)";
    // 弹出文件对话框，允许选择多个文件
    QStringList fileUrls = QFileDialog::getOpenFileNames(
                this,
                "选择 MP3 歌曲",
                defaultPath,
                filter);
    for(int i=0; i<fileUrls.size(); i++){
        QFileInfo info(fileUrls[i]);
        QString fileName = info.fileName();
        QString filePath = fileUrls[i];
        // 创建列表项并设置显示文本
        QListWidgetItem *item = new QListWidgetItem(fileName);
        // 保存文件路径到列表项的用户数据中
        item->setData(Qt::UserRole, filePath);
        // 添加到界面显示
        ui->songList->addItem(item);
        // 添加到播放列表
        this->playlist->addMedia(QMediaContent(QUrl::fromLocalFile(filePath)));
        // 插入数据库（保持原有逻辑不变）
        insertData(fileName, filePath);
    }
    ui->songList->setCurrentRow(0);
    ui->songList->show();
    if (!this->playlist->isEmpty()) {
            this->playlist->setCurrentIndex(0); // 默认播放第一首
        }
}
//播放按钮-槽
void MusicWindow::on_btn_play_clicked()
{
    QString mode = ui->btn_play->property("mode").toString();
    mode = (mode == "play") ? "pause" : "play";
    ui->btn_play->setProperty("mode", mode);
    ui->btn_play->style()->unpolish(ui->btn_play);
    ui->btn_play->style()->polish(ui->btn_play);
    ui->btn_play->update();
    (mode == "play") ? this->player->pause() : this->player->play();
}
//向前-槽
void MusicWindow::on_btn_pre_clicked()
{
    if(this->modeIndex==1){
        this->player->setPosition(0);
        this->player->play();
    }
    this->playlist->previous();
}
//向后-槽
void MusicWindow::on_btn_next_clicked()
{
    if(this->modeIndex==1){
        this->player->setPosition(0);
        this->player->play();
    }
    this->playlist->next();
}
//播放模式-槽
void MusicWindow::on_btn_mode_clicked()
{
    this->modeIndex++;
    this->modeIndex%=4;
    switch (this->modeIndex) {
        case 0: // 顺序播放
            this->playlist->setPlaybackMode(QMediaPlaylist::Sequential);
            ui->btn_mode->setProperty("mode","sequential");
            break;
        case 1: // 单曲循环
            this->playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
            ui->btn_mode->setProperty("mode","currentloop");
            break;
        case 2: // 随机播放
            this->playlist->setPlaybackMode(QMediaPlaylist::Random);
            ui->btn_mode->setProperty("mode","random");
            break;
        case 3: // 列表循环
            this->playlist->setPlaybackMode(QMediaPlaylist::Loop);
            ui->btn_mode->setProperty("mode","loop");
            break;
        }
    ui->btn_mode->style()->unpolish(ui->btn_mode);
    ui->btn_mode->style()->polish(ui->btn_mode);
    ui->btn_mode->update();
}
//歌曲进度变化
void MusicWindow::onPositionChanged()
{
    if(!this->sliderPressed)
    {
        int progress = 0;
        if(this->player->duration()!=0){
            progress = (double)this->player->position()/(double)this->player->duration()*100;
        }
        ui->music_slider->setValue(progress);
    }
    timeRender();
}
//拖动条按下
void MusicWindow::onSliderPressed()
{
    this->sliderPressed = true;
}
//拖动条释放
void MusicWindow::onSliderReleased()
{
    this->sliderPressed = false;
    qint64 change = ui->music_slider->sliderPosition()*this->player->duration()/100;
    this->player->setPosition(change);
    onPositionChanged();
    lrcUpdateForSlide();
}
//播放列表双击
void MusicWindow::on_songList_itemDoubleClicked(QListWidgetItem *item)
{
    this->item = item;
    // 1. 获取双击项的文件路径（假设已将路径存储在UserRole中）
    int index = ui->songList->row(item);
    if (index!=this->playlist->currentIndex()){
        ui->btn_play->setProperty("mode","play");
    }
    // 3. 更新播放
    this->playlist->setCurrentIndex(index);
    this->player->play();
    // 4. 高亮显示当前播放歌曲（可选）
    for (int i = 0; i < ui->songList->count(); ++i) {
        ui->songList->item(i)->setBackground(Qt::white);
    }
    item->setBackground(QColor(220, 230, 255)); // 浅蓝色背景
    on_btn_play_clicked();
}
//列表切换
void MusicWindow::on_tabWidget_currentChanged(int index)
{
    if(index==1){
        ui->onlienList->clear();
        loadOnlieMusic();
        lrcDefault();
        disconnect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::lrcGet);
        connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::lrcDefault);
    }else{
        ui->songList->clear();
        this->playlist->clear();
        selectHistory();
        disconnect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::lrcDefault);
        connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &MusicWindow::lrcGet);
    }
}
//在线列表双击
void MusicWindow::on_onlienList_itemDoubleClicked(QListWidgetItem *item)
{
    // 1. 获取双击项的文件路径（假设已将路径存储在UserRole中）
    int index = ui->onlienList->row(item);
    if (index!=this->playlist->currentIndex()){
        ui->btn_play->setProperty("mode","play");
    }
    // 3. 更新播放
    this->playlist->setCurrentIndex(index);
    this->player->play();
    // 4. 高亮显示当前播放歌曲（可选）
    for (int i = 0; i < ui->onlienList->count(); ++i) {
        ui->onlienList->item(i)->setBackground(Qt::white);
    }
    item->setBackground(QColor(220, 230, 255)); // 浅蓝色背景
    on_btn_play_clicked();
}
