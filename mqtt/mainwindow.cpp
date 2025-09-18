#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QMqttClient(this);

    // 设置MQTT服务器地址和端口
    client->setHostname("localhost");
    client->setPort(1883);

    // 连接信号和槽
    connect(client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);
    connect(client, &QMqttClient::messageReceived, this, &MainWindow::messageReceived);

    // 更新UI状态
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->subscribeButton->setEnabled(false);
    ui->publishButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    if (client->state() == QMqttClient::Disconnected) {
        client->connectToHost();
        ui->connectButton->setEnabled(false);
        ui->disconnectButton->setEnabled(true);
    }
}

void MainWindow::on_disconnectButton_clicked()
{
    if (client->state() == QMqttClient::Connected) {
        client->disconnectFromHost();
        ui->connectButton->setEnabled(true);
        ui->disconnectButton->setEnabled(false);
        ui->subscribeButton->setEnabled(false);
        ui->publishButton->setEnabled(false);
    }
}

void MainWindow::on_subscribeButton_clicked()
{
    const QString topic = ui->topicLineEdit->text();
    if (topic.isEmpty())
        return;

    auto subscription = client->subscribe(QMqttTopicFilter(topic));
    if (!subscription) {
        ui->logTextEdit->append("订阅失败!");
        return;
    }

    ui->logTextEdit->append(QString("订阅主题: %1").arg(topic));
}

void MainWindow::on_publishButton_clicked()
{
    const QString topic = ui->topicLineEdit->text();
    const QString message = ui->messageLineEdit->text();

    if (topic.isEmpty() || message.isEmpty())
        return;

    client->publish(QMqttTopicName(topic), message.toUtf8());
    ui->logTextEdit->append(QString("发布消息到主题 '%1': %2").arg(topic, message));
}

void MainWindow::updateLogStateChange()
{
    const QString content = QString("MQTT状态改变: %1").arg(client->state());
    ui->logTextEdit->append(content);

    if (client->state() == QMqttClient::Connected) {
        ui->subscribeButton->setEnabled(true);
        ui->publishButton->setEnabled(true);
    }
}

void MainWindow::brokerDisconnected()
{
    ui->logTextEdit->append("MQTT连接已断开");
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->subscribeButton->setEnabled(false);
    ui->publishButton->setEnabled(false);
}

void MainWindow::messageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    const QString content = QString("收到来自主题 '%1' 的消息: %2")
                                .arg(topic.name(), message);
    ui->logTextEdit->append(content);
}
