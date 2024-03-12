#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "vec3.h"
#include "camera.h"
#include "edge.h"

class World {
public:
    World() : cam(), vertices(1, Vec3(0, 0, 0)), edges() {};
    World(Camera cam) : cam(cam), vertices(1, Vec3(0, 0, 0)), edges() {};
    void initialize();

    void draw();
    void add_vertice(Vec3 vec3);
private:
    Camera cam;
    std::vector<Vec3> vertices;
    std::vector<Edge> edges;
};

#endif