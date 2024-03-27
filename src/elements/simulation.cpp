#include <ctime>
#include "simulation.h"
#include "iostream"

#include <random>
#include "world.h"

void Simulation::initialize() {
    sim_world.initialize();
}

void Simulation::run() {
    int frame_count = 0;
    std::time_t start_time = std::time(nullptr);

    bool quit = false;
    while (!quit) {
        SDL_Event e;
        SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    quit = true;
                } else {
                    sim_world.handle_input(e);
                }
            }

        world_render.draw();
        frame_count++;
        std::time_t current_time = std::time(nullptr);
        std::time_t duration = current_time - start_time;
        if (duration >= 1) {
            double fps = static_cast<double>(frame_count) / duration;
            std::cout << "FPS: " << fps << std::endl;
            frame_count = 0;
            start_time = std::time(nullptr);
        }
    }
}
