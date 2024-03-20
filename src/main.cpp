#include <opencv2/opencv.hpp>
#include <SDL2/SDL.h>
#include <iostream>
#include "simulation.h"

int main() {
    std::string home_dir = getenv("HOME");
    cv::VideoCapture video(std::string(home_dir) + "/Videos/indoordrone.mp4");
    if (!video.isOpened()) {
        std::cerr << "Error opening video file" << std::endl;
        return {};
    }

    int width = video.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = video.get(cv::CAP_PROP_FRAME_HEIGHT);
    int frame_count = video.get(cv::CAP_PROP_FRAME_COUNT);
    //if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //    std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    //    return 1;
    //}

    SDL_Window *video_window = nullptr;
    SDL_Renderer *video_renderer = nullptr;

    Simulation sim(video);
    sim.initialize();
    sim.run();
}