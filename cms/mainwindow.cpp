#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sys = new SystemPage(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->le_user->text();
    QString pwd = ui->le_pwd->text();
    if(username=="admin"&&pwd=="123456"){
        QMessageBox::information(this,"提示","登陆成功！");
        this->hide();
        this->sys->show();

    }
    else{
        QMessageBox::critical(this,"提示","账号或密码错误!");
    }

}
