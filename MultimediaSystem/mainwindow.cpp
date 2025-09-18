#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weatherwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer = new QTimer();
    connect(this->timer,&QTimer::timeout,this,&MainWindow::showTime);
    this->showTime();
    //新建窗口
    this->weatherWindow = new Weather(this);
    this->musicWindow = new MusicWindow(this);
    this->mapWindow = new MapWindow(this);
    this->videoWindow = new VideoWindow(this);
}

void MainWindow::showTime()
{
    QString time = QDateTime::currentDateTime().toString("HH:mm:ss");
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd ddd");
    QString dateTime = date + "\n" + time;
    ui->label_time->setText(dateTime);
    this->timer->start(1000);
}

void MainWindow::on_btn_weather_clicked()
{
    this->weatherWindow->show();
    this->hide();
}

void MainWindow::on_btn_music_clicked()
{
    this->musicWindow->show();
    this->hide();
}

void MainWindow::on_btn_location_clicked()
{
    this->mapWindow->show();
    this->hide();
}

void MainWindow::on_btn_video_clicked()
{
    this->videoWindow->show();
    this->hide();
}
