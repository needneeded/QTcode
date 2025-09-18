#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QVector>
#include <QLabel>




namespace Ui {
class MusicWindow;
}

class MusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicWindow(QWidget *parent = nullptr);
    void loadOnlieMusic();
    void insertData(QString name,QString path);
    void selectHistory();
    void timeRender();
    void lrcGet();
    void lrcDisplay();
    void lrcUpdateForSlide();
    ~MusicWindow();

public slots:
    void songIndexChang();
    void olineIndexChang();
    void voiceChange();
    void lrcDefault();

private slots:
    void on_btn_back_clicked();

    void on_btn_loadFile_clicked();

    void on_btn_play_clicked();

    void on_btn_pre_clicked();

    void on_btn_next_clicked();
    void on_btn_mode_clicked();
    void onPositionChanged();
    void onSliderPressed();
    void onSliderReleased();
    void on_songList_itemDoubleClicked(QListWidgetItem *item);
    void on_tabWidget_currentChanged(int index);
    void on_onlienList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MusicWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    int modeIndex = -1; //播放模式状态码
    bool sliderPressed = false; // 是否正在拖动进度条
    QSqlDatabase db;
    QListWidgetItem *item;
    QString time_pos = "00:00";

    QVector<QLabel*> *lyricList;
    QStringList *keys;
    QStringList *value;
};

#endif // MUSICWINDOW_H
