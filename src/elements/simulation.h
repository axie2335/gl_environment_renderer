#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "vec3.h"
#include "camera.h"
#include "edge.h"

class simulation {
public:
    simulation(camera) : camera(camera), vertices(), edges() {};
private:
    camera camera;
    std::vector<vec3> vertices;
    std::vector<edge> edges;
};

#endif