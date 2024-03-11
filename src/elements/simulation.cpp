#include "simulation.h"
#include "iostream"

void Simulation::initialize() {
    
}

void Simulation::run() {
    bool quit = false;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_P) {
                quit = true;
            }
        }
        world_render.draw();
    }
}
