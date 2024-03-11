#include "world.h"
#include <GL/glew.h> // Include GLEW before other OpenGL headers
#include <GL/glext.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

void World::draw() {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vec3), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vec3), (void*)Vec3::get_offset());
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glPointSize(5.0f); // Set point size
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, vertices.size()); // Draw points
    glBindVertexArray(0);

    // Delete VAO and VBO
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}