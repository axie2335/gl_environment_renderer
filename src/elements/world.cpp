#include "world.h"
#include <GL/glew.h> // Include GLEW before other OpenGL headers
#include <GL/glext.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <math.h>
#include <iostream>

void World::initialize() {
    y_rotation = atan2(-position[2], -position[0]) * 180.0 / M_PI + 90;
    float distance_xz = sqrt(position[0] * position[0] + position[2] * position[2]);
    x_rotation = -atan2(-position[1], distance_xz) * 180.0 / M_PI;

    for (float i = -5; i < 5; i += 0.1) {
        vertices.push_back(Vec3(i, 0, 0));
        vertices.push_back(Vec3(0, i, 0));
        vertices.push_back(Vec3(0, 0, i));
    }
}

void World::handle_input(SDL_Event event) {
    float rotation_interval = 5.0f;
    float movement_interval = 0.1f;
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
            x_rotation = x_rotation - rotation_interval < -90 ? -90 : x_rotation - rotation_interval;
        } else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
            x_rotation = x_rotation + rotation_interval > 90 ? 90 : x_rotation + rotation_interval;
        } else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
            y_rotation = fmod(y_rotation + rotation_interval, 360);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
            y_rotation = fmod(y_rotation - rotation_interval, 360);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_W) {
            float x_rotation_rad = x_rotation * (M_PI / 180);
            float y_rotation_rad = y_rotation * (M_PI / 180);
            //float z_rotation_rad = z_rotation * (M_PI / 180);
            float x_translation = sin(y_rotation_rad) * cos(x_rotation_rad) * movement_interval;
            float y_translation = -sin(x_rotation_rad) * movement_interval;
            float z_translation = -cos(y_rotation_rad) * cos(x_rotation_rad) * movement_interval;

            translate_position(x_translation, y_translation, z_translation);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_A) {
            float x_rotation_rad = x_rotation * (M_PI / 180);
            float y_rotation_rad = y_rotation * (M_PI / 180);
            //float z_rotation_rad = z_rotation * (M_PI / 180);
            float x_translation = -cos(y_rotation_rad) * movement_interval;
            float z_translation = -sin(y_rotation_rad) * movement_interval;

            translate_position(x_translation, 0, z_translation);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_S) {
            float x_rotation_rad = x_rotation * (M_PI / 180);
            float y_rotation_rad = y_rotation * (M_PI / 180);
            //float z_rotation_rad = z_rotation * (M_PI / 180);
            float x_translation = -sin(y_rotation_rad) * cos(x_rotation_rad) * movement_interval; 
            float y_translation = sin(x_rotation_rad) * movement_interval;
            float z_translation = cos(y_rotation_rad) * cos(x_rotation_rad) * movement_interval;

            translate_position(x_translation, y_translation, z_translation);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_D) {
            float x_rotation_rad = x_rotation * (M_PI / 180);
            float y_rotation_rad = y_rotation * (M_PI / 180);
            //float z_rotation_rad = z_rotation * (M_PI / 180);
            float x_translation = cos(y_rotation_rad) * movement_interval;
            //float y_translation = sin(x_rotation_rad) * sin(z_rotation_rad) * movement_interval;
            float z_translation = sin(y_rotation_rad) * movement_interval;

            translate_position(x_translation, 0, z_translation);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE) {
            translate_position(0, movement_interval, 0);
        } else if (event.key.keysym.scancode == SDL_SCANCODE_C) {
            translate_position(0, -movement_interval, 0);
        }
    }
}

void World::translate_position(float x, float y, float z) {
    position[0] += x;
    position[1] += y;
    position[2] += z;
}

void World::draw() {
    glPointSize(5.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    
    //gluPerspective(45.0f, (float)1200 / (float)1000, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();

    glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
    glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
    glTranslatef(-position[0], -position[1], -position[2]);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Upload vertex data to VBO
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vec3), vertices.data(), GL_STATIC_DRAW);

    // Specify vertex attribute pointer for position
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, sizeof(Vec3), (void*)0);
    glEnableVertexAttribArray(0);

    // Draw points
    glDrawArrays(GL_POINTS, 0, vertices.size());

    // Unbind VAO and VBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Delete VAO and VBO
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void World::add_vertice(Vec3 vec3) {
    //std::cout << "adding vertice: " << vec3[0] << ", " << vec3[1] << ", " << vec3[2] << std::endl;
    vertices.push_back(vec3);
}