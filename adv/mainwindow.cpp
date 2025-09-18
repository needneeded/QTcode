#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include "cmdlogic.h"
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->adlogic = new AdLogic();
    this->player = new QMediaPlayer();
    this->playlist = new QMediaPlaylist();
    this->vdWidget = new QVideoWidget();
    this->ardao = new AdResouceDao();

    mqttInit();
    splitterInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mqttInit()
{
    QSettings setting("C:/Users/35274/Documents/ubuntu-share/config.ini",QSettings::IniFormat);

    QString mqttUrl = setting.value("serverInfo/mqttUrl").toString();
    qDebug() << "mqttUrl:" << mqttUrl;

    this->area = setting.value("addressInfo/area").toString();
    qDebug() << "area:" <<area;

    mqClient = new QMqttClient(this);
    // 设置连接的属性
    QStringList urls = mqttUrl.split(":");
    mqClient->setHostname(urls.at(0));
    qDebug()<<mqClient->hostname();
    mqClient->setPort(urls.at(1).toInt());
    qDebug()<<mqClient->port();
    mqClient->setUsername("user");
    mqClient->setPassword("123456");
    mqClient->setClientId("qt-adv");
    mqClient->setKeepAlive(30);
    connect(this->mqClient,&QMqttClient::stateChanged,this,&MainWindow::stateChangeHandle);
    mqClient->connectToHost();
}


void MainWindow::splitterInit()
{
    // 创建主 Splitter
    QSplitter *splitter = new QSplitter(Qt::Vertical);
    this->videolist = this->ardao->selectResource(1);  // videolist[i].url 是本地路径 QString
    this->piclist = this->ardao->selectResource(2);
    qDebug() << "初始化播放资源，视频与图片列表长度：" << this->videolist.size() << "   " << this->piclist.size();

    int count = qMin(videolist.size(), piclist.size());
    if (count == 0) {
        qDebug() << "资源列表为空！";
        return;
    }

    // 创建上下部件
    QWidget *topWidget = new QWidget;
    QWidget *bottomWidget = new QWidget;

    topWidget->setStyleSheet("background-color: black;");
    bottomWidget->setStyleSheet("background-color: gray;");

    // 视频播放部分
    QVBoxLayout *topLayout = new QVBoxLayout;
    QVideoWidget *videoWidget = new QVideoWidget;
    topLayout->addWidget(videoWidget);
    topWidget->setLayout(topLayout);

    // 媒体播放器和播放列表
    QMediaPlayer *videoPlayer = new QMediaPlayer(this);
    QMediaPlaylist *playlist = new QMediaPlaylist(this);

    videoPlayer->setVideoOutput(videoWidget);
    videoPlayer->setPlaylist(playlist);

    // 添加本地视频文件
    for (int i = 0; i < count; ++i) {
        // 本地路径
        QUrl videoUrl = QUrl::fromLocalFile(videolist[i]);
        playlist->addMedia(QMediaContent(videoUrl));
    }

    // 设置循环播放
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // 图片显示
    QVBoxLayout *bottomLayout = new QVBoxLayout;
    QLabel *imageLabel = new QLabel;
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setScaledContents(true);
    bottomLayout->addWidget(imageLabel);
    bottomWidget->setLayout(bottomLayout);

    // 添加到 Splitter
    splitter->addWidget(topWidget);
    splitter->addWidget(bottomWidget);

    // 设置分屏比例
    splitter->setStretchFactor(0, 2);
    splitter->setStretchFactor(1, 1);
    splitter->setHandleWidth(0);
    QList<int> sizes;
    int height = this->height() ? this->height() : 600;
    sizes << static_cast<int>(height * 2 / 3) << static_cast<int>(height / 3);
    splitter->setSizes(sizes);

    setCentralWidget(splitter);

    // 切换图片
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, [imageLabel, count, this](int index) {
        if (index < 0 || index >= count) return;

        // 本地图片路径
        QPixmap pixmap(piclist[index]);

        if (pixmap.isNull()) {
            imageLabel->setText("图片加载失败: " + piclist[index]);
            qDebug() << "无法加载图片:" << piclist[index];
        } else {
            imageLabel->setPixmap(pixmap);
        }
    });

    // 开始播放第一个视频
    playlist->setCurrentIndex(0);  // 触发播放和图片显示
}

void MainWindow::receiveCmdMsg(QMqttMessage msg)
{
    qDebug() << "接收到cmdTopic消息:" << QString(msg.payload());

    // 解析内容中的json格式字符串，获取要做的cmd
    CmdLogic::getInstance()->execute(msg.payload());
}

void MainWindow::receiveAdlistMsg(QMqttMessage msg)
{
    qDebug() << "接收到adListTopic消息:";
    this->adlogic->dealAdPlayList(msg.payload());
}

