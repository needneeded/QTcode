#include "facerecognize.h"
#include "ui_facerecognize.h"
#include <opencv2/opencv.hpp>
#include <QSqlQuery>
#include <QSqlError>
#include <TConversion.hpp>
#include <QMessageBox>

FaceRecognize::FaceRecognize(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceRecognize)
{
    ui->setupUi(this);
    // 检测器初始化
    this->detector = new DlibFaceLivenessDetector(this);
    // 人脸工具类
    this->faceUtils = new FaceUtils("D:\\File\\RH\\opencvCode\\opencv_resource\\shape_predictor_68_face_landmarks.dat");
    // 数据库初始化
    this->db = QSqlDatabase::addDatabase("QSQLITE","recog_op");
    this->db.setDatabaseName("D:/SQLite/qt_ac.db"); // 数据库文件名
    if (!this->db.open()) {
        qDebug() << "无法打开数据库：" << this->db.lastError();
    }
}
//摄像头初始化
void FaceRecognize::cameraInit()
{
    this->back = false;
    // 创建摄像头对象，设置分辨率，获取帧，循环读取帧，帧图片转格式，样式表设置图片
    cv::VideoCapture cap(0);
    cap.set(cv::CAP_PROP_FRAME_WIDTH,350);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,220);
    // 人脸检测初始化
    cv::CascadeClassifier faceCascade;
    faceCascade.load("D:\\software\\opencv\\opencv-4.8.0\\build\\install\\etc\\haarcascades\\haarcascade_frontalcatface.xml");

    // 人脸识别：本地读取数据库数据，解析数据并计算余弦相似度，判断高于阈值则匹配成功，否则向远端发送请求
    cv::Mat frame;
    QSqlQuery query(this->db);
    query.prepare("select * from ac_data");
    query.exec();
    std::vector<float> features;
    std::vector<float> storage;
    float cosScore;
    float maxScore = 0.0;
    QString name;
    QString fStr;
    while(true)
    {
        cap >> frame;
        if(frame.empty())
        {
            qDebug()<<"摄像头画面读取失败";
            break;
        }
        //视频帧转格式显示在对应窗口
        QImage img_show(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_BGR888);
        QPixmap pix = QPixmap::fromImage(img_show);
        ui->lb_camera->setPixmap(pix);
        // 人脸检测
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(frame,faces);
        if(!faces.empty())
        {
            features = this->faceUtils->extract_face_features(frame);
        }
        // 人脸比对
        while(query.next())
        {
            name = query.value("name").toString();
            fStr = query.value("features").toString();
            qDebug() << "存储的面部向量：" << fStr;
            storage = TConversion::strToVec<float>(fStr);
            cosScore = faceUtils->calculate_cosine_similarity(features,storage);
            qDebug() << "余弦相似度：" <<cosScore;
            if(cosScore > this->recogThreshold && cosScore > maxScore)
            {
                maxScore = cosScore;
            }
        }
        if(maxScore != 0.0)
        {
            QString msg = "你好，%1";
            msg = msg.arg(name);
            QMessageBox::information(this,"提示信息",msg);
            break;
        }
        cv::waitKey(30);
        if(this->back)
        {
            //点击返回时关闭摄像头
            break;
        }
        query.first();
    }
    cap.release();
}

FaceRecognize::~FaceRecognize()
{
    this->db.close();
    delete ui;
}

void FaceRecognize::on_btn_back_clicked()
{
    this->back = true;
    this->parentWidget()->show();
    this->hide();
}

