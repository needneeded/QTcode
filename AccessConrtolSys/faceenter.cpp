#include "faceenter.h"
#include "ui_faceenter.h"
#include "TConversion.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkReply>
#include <QDebug>
#include <QUuid>

using namespace cv;
using namespace std;

//构造
FaceEnter::FaceEnter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FaceEnter)
{
    ui->setupUi(this);
    this->detector = new DlibFaceLivenessDetector(this);
    this->faceUtils = new FaceUtils("D:\\File\\RH\\opencvCode\\opencv_resource\\shape_predictor_68_face_landmarks.dat");
    this->manager = new QNetworkAccessManager(this);
    connect(this->manager,&QNetworkAccessManager::finished,this,&FaceEnter::dealReply);
    // 打开数据库操作
    this->db = QSqlDatabase::addDatabase("QSQLITE","add_op");
    this->db.setDatabaseName("D:/SQLite/qt_ac.db"); // 数据库文件名
    if (!this->db.open()) {
        qDebug() << "无法打开数据库：" << this->db.lastError();
    }
}
// 处理响应
void FaceEnter::dealReply(QNetworkReply *reply)
{
    // BUG
    // 首先检查网络错误
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "网络错误",
                              QString("无法连接到服务器: %1").arg(reply->errorString()));
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QString rst = obj.value("message").toString();
        if(rst == "success")
        {
            // 获取数据
            QString name = ui->le_name->text();
            QString phone = ui->le_phone->text();
            QString num = ui->le_num->text();
            QString fStr = TConversion::vecToStr(this->features);
            // 响应成功，开始将数据写入本地
            // 帧图像存储到本地
            QImage image(this->endFrame.data,this->endFrame.cols,this->endFrame.rows,QImage::Format_BGR888);
            QPixmap pic = QPixmap::fromImage(image);
            QString path = "D:/File/RH/opencvCode/opencv_resource/temp/%1%2.png";
            path=path.arg(name).arg(phone);
            if(!pic.save(path))
            {
                QMessageBox::critical(this,"错误提示","本地图像存储失败");
            }
            // 数据写入数据库
            QSqlQuery query(this->db);
            query.prepare("insert into ac_data(name,phone,num,features,path) values(?,?,?,?,?)");
            query.bindValue(0,name);
            query.bindValue(1,phone);
            query.bindValue(2,num);
            query.bindValue(3,fStr);
            query.bindValue(4,path);
            if (!query.exec()) {
                qDebug() << "查询失败：" << query.lastError();
                QMessageBox::critical(this,"错误信息","数据写入失败，请重试");
                return;
            }
        }
        else{
            QMessageBox::critical(this,"错误信息","远程服务器连接失败，请重试");
        }
        QMessageBox::information(this,"提示信息","人脸录入完成");
    }
}
//析构
FaceEnter::~FaceEnter()
{
    this->db.close();
    delete ui;
}
//返回按钮
void FaceEnter::on_btn_back_clicked()
{
    this->back = true;
    this->hide();
    this->parentWidget()->show();
}
//录入按钮
void FaceEnter::on_btn_enter_clicked()
{
    this->back = false;
    //打开摄像头
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        qDebug() << "摄像头打开失败" ;
        return;
    }
    //设置摄像头窗口分辨率
    cap.set(CAP_PROP_FRAME_WIDTH,350);
    cap.set(CAP_PROP_FRAME_HEIGHT,220);
    // 加载人脸检测模型
    CascadeClassifier faceCascade;
    faceCascade.load("D:\\software\\opencv\\opencv-4.8.0\\build\\install\\etc\\haarcascades\\haarcascade_frontalcatface.xml");
    //视频帧
    Mat frame;
    Mat temp;
    //整个循环用于读取视频流并显示在qt页面
    while(true)
    {
        if(this->back)
        {
            break;
        }
        cap >> frame;
        //克隆第一帧作为存储图片
        if(temp.empty())
        {
            temp = frame.clone();
            // qDebug() << "11111";
        }
        if(frame.empty())
        {
            qDebug()<<"摄像头画面读取失败";
            break;
        }
        //视频帧转格式显示在对应窗口
        QImage img_show(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_BGR888);
        QPixmap pix = QPixmap::fromImage(img_show);
        ui->cameraArea->setPixmap(pix);
        //检测框容器
        vector<Rect> faces;
        //检测人脸
        faceCascade.detectMultiScale(frame,faces);
        //如果检测到人脸则进行活体检测以及特征提取
        //眨眼检测与特征提取都封装到方法中调用
        if(!faces.empty())
        {
            //遍历框容器标注人脸
            for(Rect rect : faces)
            {
                // cvtColor(frame,frame,COLOR_BGR2RGB);
                // 在图像中标注出人脸
                rectangle(frame,rect,Scalar(0,255,0));
                QImage image(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_BGR888);
                QPixmap pix = QPixmap::fromImage(image);
                ui->cameraArea->setPixmap(pix);
            }
        }
        //眨眼检测
        bool mark = this->detector->processFrame(frame);
        if(mark)
        {
            // qDebug()<<this->detector->blinkCounter();

        }
        //眨眼频率达标，获取帧图片的面部向量特征
        if(this->detector->blinkCounter() >=3 )
        {
            //获取帧作为本地存储图像
            this->endFrame = temp.clone();
            //使用工具类获取面部特征参数
            this->features = this->faceUtils->extract_face_features(frame);
            QMessageBox::information(this,"提示","人脸信息录入完成");
            break;
        }
        //设置帧率
        waitKey(30);
    }
    //释放摄像头资源，否则再点击会产生摄像头调用冲突
    cap.release();
}
//提交按钮
void FaceEnter::on_btn_submit_clicked()
{
    QString name = ui->le_name->text();
    QString phone = ui->le_phone->text();
    QString num = ui->le_num->text();
    if(name.isEmpty() || phone.isEmpty() || num.isEmpty())
    {
        QMessageBox::critical(this,"错误提示","请正确填写住户信息");
        return;
    }
    if(this->features.size() == 0)
    {
        QMessageBox::critical(this,"错误提示","人脸信息采集未完成");
        return;
    }
    //信息包装-远程发送-本地写入-信息提示
    //模拟情况直接发送get请求，解析请求继续向下执行本地写入操作
    this->manager->get(QNetworkRequest(QUrl("http://localhost/api/send")));


}
// 多角度采集
void FaceEnter::on_btn_submit_2_clicked()
{
    // 先将摄像头资源释放
    this->back = false ;
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        qDebug() << "摄像头打开失败" ;
        return;
    }
    //设置摄像头窗口分辨率
    cap.set(CAP_PROP_FRAME_WIDTH,350);
    cap.set(CAP_PROP_FRAME_HEIGHT,220);
    Mat frame;
    int count = 0;
    int time = 0;
    QMessageBox::information(this,"提示信息","请缓慢转动头部");
    while(true)
    {
        if(this->back)
        {
            break;
        }
        cap >> frame;

        if(frame.empty())
        {
            qDebug() << "摄像头画面读取失败" ;
            return;
        }
        time+=50;
        QImage image(frame.data,frame.cols,frame.rows,QImage::Format_BGR888);
        QPixmap pic = QPixmap::fromImage(image);
        ui->cameraArea->setPixmap(pic);
        if(time%1000 == 0)
        {
            count+=1;
            QString path = "D:/File/RH/opencvCode/opencv_resource/temp/";
            QUuid id = QUuid::createUuid();
            QString id_ = id.toString(QUuid::WithoutBraces);
            path.append(id_).append(".png");
            if(!pic.save(path))
            {
                QMessageBox::critical(this,"错误提示","本地图像存储失败");
            }
        }
        if(count ==3)
        {
            QMessageBox::information(this,"提示信息","多角度采集完成");
            break;
        }
        waitKey(50);
    }
    cap.release();
}

