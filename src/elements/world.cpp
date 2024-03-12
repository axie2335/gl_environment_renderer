#include "world.h"
#include <GL/glew.h> // Include GLEW before other OpenGL headers
#include <GL/glext.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

void World::initialize() {
    for (float i = -10; i < 10; i += 0.1) {
        vertices.push_back(Vec3(i, 0, 0));
        vertices.push_back(Vec3(0, i, 0));
        vertices.push_back(Vec3(0, 0, i));
    }
}

void World::draw() {
    glPointSize(5.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vec3), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, sizeof(Vec3), (void*)0);
    glEnableVertexAttribArray(0);


    glDrawArrays(GL_POINTS, 0, vertices.size());
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

void World::add_vertice(Vec3 vec3) {
    //std::cout << "adding vertice: " << vec3[0] << ", " << vec3[1] << ", " << vec3[2] << std::endl;
    vertices.push_back(vec3);
}