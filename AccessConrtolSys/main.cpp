#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QApplication>
using namespace cv;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    // 测试opencv环境
    // Mat img = imread("D:\\File\\RH\\opencvCode\\opencv_resource\\aniya.png");
    // imshow("Test",img);
    // waitKey(0);
    // return 0;

}
