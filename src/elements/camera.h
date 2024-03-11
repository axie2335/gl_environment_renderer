#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

class Camera {
public:
    Camera() : position(Vec3(0, 0, 0)), direction(Vec3(0, 0, -1)), focal_length(0.018) {};
    Camera(Vec3 position, Vec3 direction) : position(position), direction(direction), focal_length(0.018) {};
    Camera(Vec3 position, Vec3 direction, double focal_length) : position(position), direction(direction), focal_length(focal_length) {};
private:
    Vec3 position;
    Vec3 direction;
    double focal_length;
};



/*
#include <cmath>
#include <array>

struct Camera {
    std::array<double, 3> position; // Position of the camera
    std::array<double, 3> direction; // Direction the camera is facing (unit vector)
    double fov; // Field of view (in radians)

    // Constructor
    Camera(const std::array<double, 3>& pos, const std::array<double, 3>& dir, double fieldOfView)
        : position(pos), direction(dir), fov(fieldOfView) {}

    // Update direction based on pitch and yaw angles
    void updateDirection(double pitch, double yaw) {
        // Calculate direction vector based on pitch and yaw angles
        direction[0] = cos(yaw) * cos(pitch);
        direction[1] = sin(pitch);
        direction[2] = sin(yaw) * cos(pitch);
    }
};

*/





#endif