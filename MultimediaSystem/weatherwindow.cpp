#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include "config.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>



Weather::Weather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    this->timer = new QTimer();
    connect(this->timer,&QTimer::timeout,this,&Weather::showTime);
    this->showTime();
    this->initVectors();
    this->getWeatherMsg();
}

void Weather::getWeatherMsg()
{
    QNetworkAccessManager *manage = new QNetworkAccessManager(this);
    QString url = "http://gfeljm.tianqiapi.com/api?unescape=1&version=%1&appid=%2&appsecret=%3";
    url = url.arg(WEATHER_VERSION).arg(WEATHER_APPID).arg(WEATHER_APPSECRET);
    manage->get(QNetworkRequest(QUrl(url)));
    connect(manage,&QNetworkAccessManager::finished,this,&Weather::weatherRender);
}

void Weather::weatherRender(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QString city = obj.value("city").toString();
        ui->btn_localName->setText(city);
        //解析Json为数组
        QJsonArray weatherDatas = obj.value("data").toArray();
        //遍历每天天气信息
        for(int i=0;i<weatherDatas.size();i++){
            //日期设置
            QJsonObject aDayWeaMsg = weatherDatas.at(i).toObject();
            QString date = aDayWeaMsg.value("date").toString().right(5).append("\n").append(aDayWeaMsg.value("week").toString());
//            qDebug()<<date;
            this->dates->at(i)->setText(date);
            //天气图标设置
            QString img = aDayWeaMsg.value("wea_img").toString().append(".png");
            QString iconUrl = "border-image:url(:/resource/wea_images/%1)";
            iconUrl = iconUrl.arg(img).append(";background:none;");
            this->icons->at(i)->setStyleSheet(iconUrl);
            //天气文本
            QString wea = aDayWeaMsg.value("wea").toString();
            this->weas->at(i)->setText(wea);
            //温度区间
            QString t_range = aDayWeaMsg.value("tem1").toString().append("℃\n").append(aDayWeaMsg.value("tem2").toString().append("℃"));
            this->temperatures->at(i)->setText(t_range);

            //当天天气详情
            if(i==0){
                ui->label_tem->setText(aDayWeaMsg.value("tem").toString().append("℃"));
                ui->label_temMax->setText(aDayWeaMsg.value("tem1").toString().append("℃"));
                ui->label_temMin->setText(aDayWeaMsg.value("tem2").toString().append("℃"));
                ui->label_wea->setText(wea);
                ui->label_weatherIcon->setStyleSheet(iconUrl);

            }
        }


    }
}

void Weather::initVectors()
{
    this->dates = new QVector<QLabel*>();
    this->dates->push_back(ui->label_date1);
    this->dates->push_back(ui->label_date2);
    this->dates->push_back(ui->label_date3);
    this->dates->push_back(ui->label_date4);
    this->dates->push_back(ui->label_date5);
    this->dates->push_back(ui->label_date6);
    this->dates->push_back(ui->label_date7);

    this->icons = new QVector<QLabel*>();
    this->icons->push_back(ui->label_icon1);
    this->icons->push_back(ui->label_icon2);
    this->icons->push_back(ui->label_icon3);
    this->icons->push_back(ui->label_icon4);
    this->icons->push_back(ui->label_icon5);
    this->icons->push_back(ui->label_icon6);
    this->icons->push_back(ui->label_icon7);

    this->temperatures = new QVector<QLabel*>();
    this->temperatures->push_back(ui->label_temperature1);
    this->temperatures->push_back(ui->label_temperature2);
    this->temperatures->push_back(ui->label_temperature3);
    this->temperatures->push_back(ui->label_temperature4);
    this->temperatures->push_back(ui->label_temperature5);
    this->temperatures->push_back(ui->label_temperature6);
    this->temperatures->push_back(ui->label_temperature7);

    this->weas = new QVector<QLabel*>();
    this->weas->push_back(ui->label_wea1);
    this->weas->push_back(ui->label_wea2);
    this->weas->push_back(ui->label_wea3);
    this->weas->push_back(ui->label_wea4);
    this->weas->push_back(ui->label_wea5);
    this->weas->push_back(ui->label_wea6);
    this->weas->push_back(ui->label_wea7);

}

Weather::~Weather()
{
    delete ui;
}

void Weather::showTime()
{
    QString time = QDateTime::currentDateTime().toString("HH:mm:ss");
    QString date = QDateTime::currentDateTime().toString("yyyy-MM-dd ddd");
    QString dateTime = date + "\n" + time;
    ui->label_datetime->setText(dateTime);
    this->timer->start(1000);
}

void Weather::on_btn_backIcon_clicked()
{
    this->hide();
    this->parentWidget()->show();
}

