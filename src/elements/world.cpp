#include "world.h"
#include <GL/glew.h> // Include GLEW before other OpenGL headers
#include <GL/glext.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

void World::initialize() {
    for (float i = -5; i < 5; i += 0.1) {
        vertices.push_back(Vec3(i, 0, 0));
        vertices.push_back(Vec3(0, i, 0));
        vertices.push_back(Vec3(0, 0, i));
    }
}

void World::draw() {
    glPointSize(5.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear both color and depth buffers

    // Set up model-view and projection matrices
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Apply perspective projection
    gluPerspective(45.0f, (float)1200 / (float)1000, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Apply camera transformations
    glTranslatef(cam.x(), cam.y(), cam.z()); // Move the camera back along the z-axis
    cam.translate(0, 0, -0.01);
    x_rotation += 0.5;
    x_rotation = fmod(x_rotation, 360);
    y_rotation += 0.5;
    x_rotation = fmod(y_rotation, 360);
    z_rotation += 0.5;
    z_rotation = fmod(z_rotation, 360);
    glRotatef(x_rotation, 1.0f, 0.0f, 0.0f); // Rotate the camera around the x-axis
    glRotatef(y_rotation, 0.0f, 1.0f, 0.0f); // Rotate the camera around the y-axis
    glRotatef(z_rotation, 0.0f, 0.0f, 1.0f);

    // Generate and bind vertex array object (VAO)
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Generate and bind vertex buffer object (VBO)
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