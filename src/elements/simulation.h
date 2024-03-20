#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "simulationrender.h"
#include <opencv2/opencv.hpp>

class Simulation {
public:
    Simulation(cv::VideoCapture video) : sim_world(), world_render(sim_world, video) {};
    void initialize();
    void run();
private:
    World sim_world;
    SimulationRender world_render;
};

#endif