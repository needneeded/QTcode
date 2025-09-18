#ifndef FACEENTER_H
#define FACEENTER_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "dlibfacelivenessdetector.h"
#include "faceutils.h"
#include <QSqlDatabase>

namespace Ui {
class FaceEnter;
}

class FaceEnter : public QMainWindow
{
    Q_OBJECT

public:
    explicit FaceEnter(QWidget *parent = nullptr);
    void dealReply(QNetworkReply *reply);
    ~FaceEnter();

private slots:
    void on_btn_back_clicked();
    void on_btn_enter_clicked();

    void on_btn_submit_clicked();

    void on_btn_submit_2_clicked();

private:
    Ui::FaceEnter *ui;
    DlibFaceLivenessDetector *detector;
    FaceUtils *faceUtils;
    cv::Mat endFrame;
    std::vector<float> features;
    QNetworkAccessManager *manager;
    QSqlDatabase db;
    bool back ;
};

#endif // FACEENTER_H
