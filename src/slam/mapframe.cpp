#include "mapframe.h"

void MapFrame::add_point(int width, int height) {
    if (height < 0 || height > this->mat.rows || width < 0 || width > this->mat.cols) {
        std::cerr << "Coordinates placed outside of boundary: " << height << ", " << width << std::endl;
    }
    this->points.push_back({width, height});
}

cv::Mat MapFrame::draw_mat() {
    //std::cout << this->mat.rows << " " << this->mat.cols << std::endl;
    if (this->mat.rows <= 0 || this->mat.cols <= 0) {
        std::cerr << "Error: Invalid input matrix dimensions." << std::endl;
        return cv::Mat(); 
    }
    cv::Mat newmat(this->mat.rows, this->mat.cols, CV_8UC3);


    for (auto point = this->points.begin(); point != this->points.end(); point++) {
        int x = (*point)[0];
        int y = (*point)[1];

        for (int ypt = y - 1; ypt <= y + 1; ypt++) {
            if (ypt < 0 || ypt >= this->mat.rows) {
                continue;
            }
            for (int xpt = x - 1; xpt <= x + 1; xpt++) { 
                if (xpt < 0 || xpt >= this->mat.cols) {
                    continue;
                }
                cv::Vec3b &pixel = this->mat.at<cv::Vec3b>(ypt, xpt); 
                pixel[1] = 0xFF;
            }
        }
    }
    

    return this->mat;
}