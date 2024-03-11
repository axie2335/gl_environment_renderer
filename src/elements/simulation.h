#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"

class simulation {
public:
    simulation() : sim_world() {};
    void run();
private:
    world sim_world;
};

#endif