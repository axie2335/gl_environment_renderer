#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "vec3.h"
#include "camera.h"
#include "edge.h"

class World {
public:
    World() : cam(), vertices(), edges() {};
    World(Camera cam) : cam(cam), vertices(), edges() {};
    void draw();
private:
    Camera cam;
    std::vector<Vec3> vertices{Vec3(0, 0, 0)};
    std::vector<Edge> edges;
};

#endif