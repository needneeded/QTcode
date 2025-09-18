#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QVBoxLayout>

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();
    void videoPlay(QString path);
    void insertData(QString name, QString path);
    void loadHistory();
    bool eventFilter(QObject *obj, QEvent *event);
    void onlineInit();
private slots:
    void videoIndexChang();

    void on_btn_exit_clicked();

    void on_btn_loadFile_clicked();

    void on_btn_mode_clicked();

    void on_btn_pre_clicked();

    void on_btn_next_clicked();

    void on_voiceSlider_valueChanged(int value);

    void on_btn_fullScreen_clicked();

    void on_localList_itemDoubleClicked(QListWidgetItem *item);

    void on_tabWidget_currentChanged(int index);

    void on_onlineList_itemDoubleClicked(QListWidgetItem *item);

    void on_playbackSpeed_currentIndexChanged(int index);

private:
    Ui::VideoWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *vWid;
    QSqlDatabase db;
    QVBoxLayout *mainLayout;    // 主布局
    QWidget *fullscreenWidget;  // 全屏窗口
    bool isFullscreen;
    QVBoxLayout *originalLayout;
    QWidget *originalParent;
    qreal rate = 1;

};

#endif // VIDEOWINDOW_H
