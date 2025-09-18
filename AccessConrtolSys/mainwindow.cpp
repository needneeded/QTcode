#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->faceWin = new FaceEnter(this);
    this->faceRecog = new FaceRecognize(this);
    connect(this,&MainWindow::cInit,MainWindow::faceRecog,&FaceRecognize::cameraInit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_enter_clicked()
{
    this->faceWin->show();
    this->hide();
}

void MainWindow::on_btn_recognize_clicked()
{
    this->faceRecog->show();
    this->hide();
    emit cInit();
}
