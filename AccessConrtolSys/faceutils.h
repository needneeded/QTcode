#ifndef FACEUTILS_H
#define FACEUTILS_H

#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <dlib/image_processing/frontal_face_detector.h>
#include <cmath>

class FaceUtils {
public:
    // 初始化人脸检测器和关键点预测器
    FaceUtils(const std::string& landmark_model_path);

    // 从图像中提取人脸几何特征向量
    std::vector<float> extract_face_features(const cv::Mat& image);

    // 计算两个特征向量的欧氏距离
    static float calculate_euclidean_distance( const std::vector<float>& features1,const std::vector<float>& features2);

    // 计算余弦相似度
    static float calculate_cosine_similarity(const std::vector<float>& features1, const std::vector<float>& features2);

private:
    dlib::frontal_face_detector detector;
    dlib::shape_predictor predictor;

    // 从68个关键点生成几何特征
    std::vector<float> _extract_geometric_features(const dlib::full_object_detection& landmarks);
};

#endif // FACEUTILS_H
