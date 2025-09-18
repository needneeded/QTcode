#ifndef FACERECOGNIZE_H
#define FACERECOGNIZE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "faceutils.h"
#include <dlibfacelivenessdetector.h>
namespace Ui {
class FaceRecognize;
}

class FaceRecognize : public QMainWindow
{
    Q_OBJECT

public:
    explicit FaceRecognize(QWidget *parent = nullptr);

    ~FaceRecognize();

private slots:
    void on_btn_back_clicked();
public slots:
    void cameraInit();
private:
    Ui::FaceRecognize *ui;
    bool back = false;
    QSqlDatabase db;
    FaceUtils *faceUtils;
    DlibFaceLivenessDetector *detector;
    const float recogThreshold = 0.95;
};

#endif // FACERECOGNIZE_H
