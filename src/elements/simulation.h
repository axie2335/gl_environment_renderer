#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "simulationrender.h"

class Simulation {
public:
    Simulation() : sim_world(), world_render(sim_world) {};
    void initialize();
    void run();
private:
    World sim_world;
    SimulationRender world_render;
};

#endif