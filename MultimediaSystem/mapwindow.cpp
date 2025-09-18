#include "mapwindow.h"
#include "ui_mapwindow.h"
#include <config.h>
#include <QFile>
#include <QPixmap>
#include <QNetworkReply>
#include <QMessageBox>
#include <mainwindow.h>
#include <QTouchEvent>
#include <cmath>
#include <QStyleFactory>


MapWindow::MapWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    this->manager = new QNetworkAccessManager();
    initMap();
    //拖拽地图
    this->installEventFilter(this);


}

bool MapWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this) {
        switch (event->type()) {
        case QEvent::MouseButtonPress: {
            pres_flag = true;
            last_point = mapFromGlobal(QCursor::pos());
            break;
        }
        case QEvent::MouseButtonRelease: {
            if (pres_flag) {  // 只有在按下的前提下才触发 release
                rele_flag = true;
                point = mapFromGlobal(QCursor::pos());
            }
            break;
        }
        case QEvent::TouchBegin: {
            QTouchEvent *touch = static_cast<QTouchEvent*>(event);
            point = touch->touchPoints().at(0).pos().toPoint();
            pres_flag = true;
            rele_flag = true;
            event->accept();
            break;
        }
        default:
            break;
        }
    }

    // 只在满足按下+释放时执行一次
    if (pres_flag && rele_flag) {
        pres_flag = false;     // 立即重置标志位
        rele_flag = false;

        double m_x = point.x() - last_point.x();
        double m_y = point.y() - last_point.y();

        if (abs(m_x) > 10 || abs(m_y) > 10) {
            // 计算新的经纬度
            int m_zoom = this->zoom;
            double factor = (19 - m_zoom);
            double move_factor = 0.00000003 * factor * factor * factor * factor;

            east -= m_x * move_factor;
            north += m_y * move_factor;

            east = round(east * 1e6) / 1e6;
            north = round(north * 1e6) / 1e6;

            QString url = QString(MAP_URL).arg(east).arg(north).arg(m_zoom).arg(east).arg(north).arg(MAP_KEY);
            initMap(url);
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

void MapWindow::showZoomLimitMessage(const QString &message) {
    QMessageBox::critical(this,"提示",message);
}

void MapWindow::initMap()
{

    QString url = QString(MAP_URL).arg(this->east).arg(this->north).arg(this->zoom).arg(this->east).arg(this->north).arg(MAP_KEY);
    this->manager->get(QNetworkRequest(QUrl(url)));
    connect(this->manager,&QNetworkAccessManager::finished,this,&MapWindow::showMap);
}

void MapWindow::initMap(QString url)
{
//    qDebug()<< url;
    this->manager->get(QNetworkRequest(QUrl(url)));
    connect(this->manager,&QNetworkAccessManager::finished,this,&MapWindow::showMap);
}

void MapWindow::showMap(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QFile file("./images/temp.png");
    file.open(QIODevice::ReadWrite);
    file.write(data);
    file.close();
    QPixmap map("./images/temp.png");
    ui->lb_bacground->setPixmap(map);
}

void MapWindow::initIp()
{
    QString url = "www.ipinfo.io/ip";
    this->manager->get(QNetworkRequest(QUrl(url)));
    connect(this->manager,&QNetworkAccessManager::finished,this,&MapWindow::getIp);
}

void MapWindow::getIp(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString ip = QString(data);
//    qDebug()<<ip;

}

MapWindow::~MapWindow()
{
    delete ui;
}

void MapWindow::on_btn_exit_clicked()
{
    this->hide();
    this->parentWidget()->show();

}

void MapWindow::on_btn_zoomIn_clicked()
{
    if(this->zoom >= 17){
         showZoomLimitMessage("当前地图已最大化，无法继续放大");
    }
    this->zoom++;
    initMap();
}

void MapWindow::on_btn_zoomOut_clicked()
{
    if(this->zoom<=3){
        showZoomLimitMessage("当前地图已最小化，无法继续缩小");
    }
    else{
        this->zoom--;
    }

    initMap();
}
