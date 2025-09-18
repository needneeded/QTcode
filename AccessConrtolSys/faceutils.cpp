#include "FaceUtils.h"
#include <dlib/image_io.h>
#include <QDebug>

FaceUtils::FaceUtils(const std::string& landmark_model_path) {
    detector = dlib::get_frontal_face_detector();
    dlib::deserialize(landmark_model_path) >> predictor;
    try {
        detector = dlib::get_frontal_face_detector();
        dlib::deserialize(landmark_model_path) >> predictor;
    } catch (const std::exception &e) {
        qDebug() << "Model loading failed:" << e.what();
    }
}

std::vector<float> FaceUtils::extract_face_features(const cv::Mat& image) {
    //将输入的OpenCV格式图像转换为dlib库支持的图像格式 dlib::cv_image。
    dlib::cv_image<dlib::bgr_pixel> dlib_image(image);
    //使用dlib的人脸检测器检测图像中的所有可能人脸，返回人脸位置的矩形框列表。
    std::vector<dlib::rectangle> faces = detector(dlib_image);

    // 说明未检测到任何人脸
    if (faces.empty()) {
        return {};
    }

    // 只处理第一张人脸
    dlib::full_object_detection landmarks = predictor(dlib_image, faces[0]);
    return _extract_geometric_features(landmarks);
}

std::vector<float> FaceUtils::_extract_geometric_features(
    const dlib::full_object_detection& landmarks) {

    std::vector<float> features;

    // 计算两眼之间的距离
    float left_eye_x = landmarks.part(39).x();  // 左眼内角（点36）
    float right_eye_x = landmarks.part(42).x(); // 右眼内角（点42）
    // 计算两眼间的欧氏距离
    float eye_dist = std::sqrt(
        std::pow(left_eye_x - right_eye_x, 2) +
        std::pow(landmarks.part(39).y() - landmarks.part(42).y(), 2)
        );
    features.push_back(eye_dist);

    // 嘴巴宽高比
    float mouth_width = std::abs(landmarks.part(54).x() - landmarks.part(48).x());
    float mouth_height = std::abs(landmarks.part(57).y() - landmarks.part(51).y());
    features.push_back(mouth_width / mouth_height);

    // 鼻子到下巴的垂直距离
    float nose_to_chin = std::abs(landmarks.part(33).y() - landmarks.part(8).y());
    features.push_back(nose_to_chin);

    // 添加更多几何特征...
    float eyebrow_curve = 0.0f;
    for (int i = 17; i < 21; ++i) {
        float dx = landmarks.part(i+1).x() - landmarks.part(i).x();
        float dy = landmarks.part(i+1).y() - landmarks.part(i).y();
        eyebrow_curve += std::sqrt(dx*dx + dy*dy);
    }
    features.push_back(eyebrow_curve);

    return features;
}

float FaceUtils::calculate_euclidean_distance(
    const std::vector<float>& features1,
    const std::vector<float>& features2) {

    if (features1.size() != features2.size()) {
        return -1.0;  // 错误码
    }

    float sum = 0.0;
    for (size_t i = 0; i < features1.size(); i++) {
        sum += std::pow(features1[i] - features2[i], 2);
    }
    return std::sqrt(sum);
}

float FaceUtils::calculate_cosine_similarity(
    const std::vector<float>& features1,
    const std::vector<float>& features2) {

    if (features1.size() != features2.size()) {
        return -1.0;  // 错误码
    }

    float dot_product = 0.0, norm1 = 0.0, norm2 = 0.0;
    for (size_t i = 0; i < features1.size(); i++) {
        dot_product += features1[i] * features2[i];
        norm1 += std::pow(features1[i], 2);
        norm2 += std::pow(features2[i], 2);
    }
    return dot_product / (std::sqrt(norm1) * std::sqrt(norm2));
}
