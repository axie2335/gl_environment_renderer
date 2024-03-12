#include <ctime>
#include "simulation.h"
#include "iostream"

#include <random>
#include "world.h"

void Simulation::initialize() {
    
}

void Simulation::run() {
    int frame_count = 0;
    std::time_t start_time = std::time(nullptr);

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

        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<float> dis(-1, 1);
        sim_world.add_vertice(Vec3(dis(gen), dis(gen), dis(gen)));

        world_render.draw();
        frame_count++;
        std::time_t current_time = std::time(nullptr);
        std::time_t duration = current_time - start_time;
        if (duration >= 1) {
            double fps = static_cast<double>(frame_count) / duration;
            std::cout << "FPS: " << fps << std::endl;

            // Reset frame count and start time
            frame_count = 0;
            start_time = std::time(nullptr);
        }
    }
}
