#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "vec3.h"
#include "camera.h"
#include "edge.h"

class world {
public:
    world() : cam(), vertices(), edges() {};
    world(camera cam) : cam(cam), vertices(), edges() {};
private:
    camera cam;
    std::vector<vec3> vertices;
    std::vector<edge> edges;
};

#endif