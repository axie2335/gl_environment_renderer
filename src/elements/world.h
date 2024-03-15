#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "vec3.h"
#include "camera.h"
#include "edge.h"

class World {
public:
    World() : cam(), vertices(), edges(), 
        x_rotation(0), y_rotation(0), z_rotation(0) {};
    World(Camera cam) : cam(cam), vertices(), edges(), x_rotation(0) {};
    void initialize();

    void draw();
    void add_vertice(Vec3 vec3);
private:
    Camera cam;
    std::vector<Vec3> vertices;
    std::vector<Edge> edges;
    float x_rotation;
    float y_rotation;
    float z_rotation;
};

#endif