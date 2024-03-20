#ifndef MAPFRAME_H
#define MAPFRAME_H

#include <opencv2/opencv.hpp>

class MapFrame {
public:
    MapFrame(cv::Mat mat) : mat(mat) {};
    void add_point(int width, int height);
    cv::Mat draw_mat();
private:
    cv::Mat mat;
    std::vector<std::array<int, 2>> points;
};






#endif