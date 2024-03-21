#include "simulationrender.h"
#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <unistd.h>

void SimulationRender::initialize_window(cv::VideoCapture video) {
    this->width = video.get(cv::CAP_PROP_FRAME_WIDTH);
    this->height = video.get(cv::CAP_PROP_FRAME_HEIGHT);
    int frame_count = video.get(cv::CAP_PROP_FRAME_COUNT);

    map_frames.reserve(frame_count);

    cv::Mat frame;
    std::cout << std::endl;
    while (video.read(frame)) {
        map_frames.push_back(MapFrame(frame.clone()));
    } 
    cur_frame = map_frames.begin();

    std::cout << "Finished processing!" << std::endl;
    int width = 1200;
    int height = 1000;
    map_window = nullptr;
    Uint32 window_flags = SDL_WINDOW_OPENGL;
    map_window = SDL_CreateWindow("Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, window_flags);

    map_context = SDL_GL_CreateContext(map_window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(err));
        SDL_DestroyWindow(map_window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    
    glViewport(0, 0, width, height); // Set the viewport

    glMatrixMode(GL_PROJECTION); // Set matrix mode to projection
    glLoadIdentity(); // Load identity matrix

    float aspectRatio = (float)width / (float)height;
    float fov = 45.0f; // Field of view angle
    float nearPlane = 0.01f; // Near clipping plane
    float farPlane = 10000.0f; // Far clipping plane

    // Define perspective projection
    gluPerspective(fov, aspectRatio, nearPlane, farPlane);

    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix mode

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    video_window = nullptr;
    video_window = SDL_CreateWindow("video", 100, 100, this->width, this->height, SDL_WINDOW_SHOWN);
    video_renderer = SDL_CreateRenderer(video_window, -1, SDL_RENDERER_ACCELERATED);

}

void SimulationRender::draw() {
    SDL_GL_MakeCurrent(map_window, map_context);
    glClear(GL_COLOR_BUFFER_BIT);

    world.draw();
    SDL_GL_SwapWindow(map_window);
    
    SDL_GL_MakeCurrent(map_window, nullptr);

    SDL_RenderClear(video_renderer);
    MapFrame &frame = *cur_frame;
    if (cur_frame != map_frames.end()) {
        cur_frame++;
        cv::Mat mat = frame.draw_mat();
        SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(mat.data, width, height, 24, 3 * width, 0xFF0000, 0x00FF00, 0x0000FF, 0);

    texture = SDL_CreateTextureFromSurface(video_renderer, surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(video_renderer, texture, NULL, NULL);
    SDL_RenderPresent(video_renderer);
    }
    //usleep(500);
}