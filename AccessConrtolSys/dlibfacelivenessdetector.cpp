#include "dlibfacelivenessdetector.h"
#include <QDebug>

DlibFaceLivenessDetector::DlibFaceLivenessDetector(QObject *parent)
    : QObject(parent),
    m_faceDetector(dlib::get_frontal_face_detector())
{
    QString landmarkModelPath = "D:\\File\\RH\\opencvCode\\opencv_resource\\shape_predictor_68_face_landmarks.dat";
    dlib::deserialize(landmarkModelPath.toStdString()) >> m_shapePredictor;
    m_isInitialized = true;
}

DlibFaceLivenessDetector::~DlibFaceLivenessDetector()
{
}


bool DlibFaceLivenessDetector::processFrame(cv::Mat &frame)
{
    if (!m_isInitialized || frame.empty()) {
        return false;
    }

    bool isBlinking = false;
    dlib::cv_image<dlib::bgr_pixel> dlibImage(frame);

    // 检测人脸
    std::vector<dlib::rectangle> faces = m_faceDetector(dlibImage);

    for (const auto& face : faces) {
        dlib::full_object_detection shape = m_shapePredictor(dlibImage, face);

        // 计算左右眼EAR
        double leftEAR = calculateEAR(shape, 36, 41);
        double rightEAR = calculateEAR(shape, 42, 47);
        double avgEAR = (leftEAR + rightEAR) / 2.0;

        // 判断是否眨眼
        if (avgEAR < m_earThreshold) {
            m_blinkCounter++;
            if (m_blinkCounter >= m_blinkConsectiveFrames) {
                isBlinking = true;
                emit livenessDetected();
                // cv::putText(frame, "LIVENESS DETECTED", cv::Point(10, 60),
                //             cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(0, 255, 0), 2);
            }
        } else {
            m_blinkCounter = 0;
        }

        // 可视化
        // cv::rectangle(frame,
        //               cv::Point(face.left(), face.top()),
        //               cv::Point(face.right(), face.bottom()),
        //               cv::Scalar(0, 255, 0), 2);

        // cv::putText(frame, QString("EAR: %1").arg(avgEAR, 0, 'f', 2).toStdString(),
        //             cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.7,
        //             isBlinking ? cv::Scalar(0, 255, 0) : cv::Scalar(0, 0, 255), 2);
    }

    return isBlinking;
}

double DlibFaceLivenessDetector::calculateEAR(
    const dlib::full_object_detection &shape, int eyeStart, int eyeEnd) const
{
    std::vector<dlib::point> eyePoints;
    for (int i = eyeStart; i <= eyeEnd; ++i) {
        eyePoints.push_back(shape.part(i));
    }

    double A = dlib::length(eyePoints[1] - eyePoints[5]);
    double B = dlib::length(eyePoints[2] - eyePoints[4]);
    double C = dlib::length(eyePoints[0] - eyePoints[3]);

    return (A + B) / (2.0 * C);
}

int DlibFaceLivenessDetector::blinkCounter() const
{
    return m_blinkCounter;
}

void DlibFaceLivenessDetector::setBlinkCounter(int newBlinkCounter)
{
    m_blinkCounter = newBlinkCounter;
}

void DlibFaceLivenessDetector::setEARThreshold(double threshold)
{
    m_earThreshold = qBound(0.1, threshold, 0.5);
}

double DlibFaceLivenessDetector::getEARThreshold() const
{
    return m_earThreshold;
}
