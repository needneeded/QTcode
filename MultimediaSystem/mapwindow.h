#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <config.h>
namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = nullptr);
    void initMap();
    void initMap(QString url);
    void showMap(QNetworkReply *reply);
    void initIp();
    void getIp(QNetworkReply *reply);
    bool eventFilter(QObject *watched, QEvent *event) override;
    void showZoomLimitMessage(const QString &message);

    ~MapWindow();

private slots:
    void on_btn_exit_clicked();

    void on_btn_zoomIn_clicked();

    void on_btn_zoomOut_clicked();

private:
    Ui::MapWindow *ui;
    QNetworkAccessManager *manager;
    int zoom = 13;

    QPoint point, last_point;
    bool pres_flag = false;
    bool rele_flag = false;
    double east = QString(MAP_LNG).toDouble();
    double north = QString(MAP_LAT).toDouble();

};

#endif // MAPWINDOW_H
