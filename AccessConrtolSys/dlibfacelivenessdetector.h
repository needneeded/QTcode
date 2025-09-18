#ifndef DlibFaceLivenessDetector_H
#define DlibFaceLivenessDetector_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>

class DlibFaceLivenessDetector : public QObject
{
    Q_OBJECT
public:
    explicit DlibFaceLivenessDetector(QObject *parent = nullptr);
    ~DlibFaceLivenessDetector();


    // 处理帧图像（返回是否检测到眨眼）
    bool processFrame(cv::Mat &frame);

    // 设置/获取EAR阈值（默认0.25）
    void setEARThreshold(double threshold);
    double getEARThreshold() const;

    // 眨眼次数
    int blinkCounter() const;
    void setBlinkCounter(int newBlinkCounter);

signals:
    // 检测到活体信号
    void livenessDetected();

private:
    // 计算眼睛纵横比
    double calculateEAR(const dlib::full_object_detection &shape, int eyeStart, int eyeEnd) const;

    // DLib组件
    dlib::frontal_face_detector m_faceDetector;
    dlib::shape_predictor m_shapePredictor;
    bool m_isInitialized = false;

    // 配置参数
    double m_earThreshold = 0.25;
    const int m_blinkConsectiveFrames = 3;
    int m_blinkCounter = 0;
};

#endif // DlibFaceLivenessDetector_H
