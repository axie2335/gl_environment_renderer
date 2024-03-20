#ifndef RENDERER_H
#define RENDERER_H

#include "world.h"
#include <SDL2/SDL.h>
#include "mapframe.h"
#include <opencv2/opencv.hpp>

class SimulationRender {
public:
    SimulationRender(World &world, cv::VideoCapture video): world(world) { initialize_window(video); };
    void draw(); 
private:
    void initialize_window(cv::VideoCapture);
    int width;
    int height;
    std::vector<MapFrame> map_frames;
    std::vector<MapFrame>::iterator cur_frame;
    SDL_Window *map_window;
    SDL_GLContext map_context;
    SDL_Window *video_window;
    SDL_Renderer *video_renderer;
    SDL_Texture *texture;
    World &world;
};

#endif