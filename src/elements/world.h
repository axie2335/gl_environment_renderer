#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <vector>
#include "vec3.h"
#include "edge.h"

class World {
public:
    World() : vertices(), edges(), position{-1, 1, 1},
        x_rotation(0), y_rotation(0) {};
    void initialize();
    void handle_input(SDL_Event event);
    void draw();
    void add_vertice(Vec3 vec3);
    void translate_position(float, float, float);
private:
    std::vector<Vec3> vertices;
    std::vector<Edge> edges;
    float position[3];
    float x_rotation;
    float y_rotation;
    float z_rotation;
};

#endif