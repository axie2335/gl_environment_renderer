#ifndef RENDERER_H
#define RENDERER_H

#include "world.h"
#include <SDL2/SDL.h>

class SimulationRender {
public:
    SimulationRender(World &world): world(world) { initialize_window(); };
    void draw(); 
private:
    void initialize_window();
    SDL_Window *window;
    World &world;
};

#endif