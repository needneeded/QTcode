#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <weatherwindow.h>
#include <musicwindow.h>
#include <mapwindow.h>
#include <videowindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow()
    {
        delete ui;
    }
public slots:
    void showTime();
private slots:
    void on_btn_weather_clicked();

    void on_btn_music_clicked();

    void on_btn_location_clicked();

    void on_btn_video_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Weather *weatherWindow;
    MusicWindow *musicWindow;
    MapWindow *mapWindow;
    VideoWindow *videoWindow;

};
#endif // MAINWINDOW_H
