#include "simulationrender.h"
#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

void SimulationRender::initialize_window() {
    int width = 1200;
    int height = 1000;
    window = nullptr;
    Uint32 window_flags = SDL_WINDOW_OPENGL;
    window = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(err));
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void SimulationRender::draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    world.draw();
    SDL_GL_SwapWindow(window);
}