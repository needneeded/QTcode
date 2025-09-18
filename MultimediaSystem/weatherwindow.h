#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QMainWindow>
#include <QNetworkReply>
#include <QLabel>

namespace Ui {
class Weather;
}

class Weather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    void getWeatherMsg();
    void weatherRender(QNetworkReply *reply);
    void initVectors();
    ~Weather();
public slots:
    void showTime();
private slots:
    void on_btn_backIcon_clicked();

private:
    Ui::Weather *ui;
    QTimer *timer;
    QVector<QLabel*> *dates;
    QVector<QLabel*> *icons;
    QVector<QLabel*> *temperatures;
    QVector<QLabel*> *weas;

};

#endif // WEATHER_H
