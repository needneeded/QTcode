#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmqttclient.h>
#include "adlogic.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <adresourcedao.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mqttInit();
    void uiRender();
    void splitterInit();

public slots:
    void stateChangeHandle();
    void receiveCmdMsg(QMqttMessage msg);
    void receiveAdlistMsg(QMqttMessage msg);

private:
    Ui::MainWindow *ui;
    QMqttClient *mqClient;
    QString area;
    AdLogic *adlogic;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *vdWidget;
    QList<QString> videolist;
    QList<QString> piclist;
    AdResouceDao *ardao;

};
#endif // MAINWINDOW_H
