#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "faceenter.h"
#include "facerecognize.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void cInit();

private slots:
    void on_btn_enter_clicked();

    void on_btn_recognize_clicked();

private:
    Ui::MainWindow *ui;
    FaceEnter *faceWin;
    FaceRecognize *faceRecog;
};
#endif // MAINWINDOW_H
