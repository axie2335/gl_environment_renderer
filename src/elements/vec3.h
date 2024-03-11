#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3 {
public:
    vec3() : v{0, 0, 0} {};
    vec3(double v1, double v2, double v3) : v{v1, v2, v3} {};

    double operator[](int i) const { return v[i]; };
    double &operator[](int i) { return v[i]; };
    vec3 operator-() { return vec3{-v[0], -v[1], -v[2]}; };

    vec3 &operator+=(const vec3 &vec) { 
        v[0] += vec[0];
        v[1] += vec[1];
        v[2] += vec[2];
        return *this; 
    };

    vec3 &operator-=(const vec3 &vec) { 
        v[0] -= vec[0];
        v[1] -= vec[1];
        v[2] -= vec[2];
        return *this; 
    };

    vec3 &operator*=(double val) {
        v[0] *= val;
        v[1] *= val;
        v[2] *= val;
        return *this;
    }

    vec3 &operator/=(double val) {
        v[0] /= val;
        v[1] /= val;
        v[2] /= val;
        return *this;
    }

    vec3 &operator*=(const vec3 &vec) {
        v[0] *= vec[0];
        v[1] *= vec[1];
        v[2] *= vec[2];
        return *this;
    }

    double length() const {
        return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    }

    double length_squared() const {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    }

    vec3 unit_vector() {
        return *this / this->length();
    }

private:
    double v[3];
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline vec3 operator*(const vec3 &v, const vec3 &u) {
    return vec3(v[0] * u[0], v[1] * u[1], v[2] * u[2]);
}

inline vec3 operator*(const vec3 &v, double val) {
    return vec3(v[0] * val, v[1] * val, v[2] * val);
}

inline vec3 operator*(double val, const vec3 &v) {
    return vec3(v[0] * val, v[1] * val, v[2] * val);
}

inline vec3 operator/(const vec3 &v, double val) {
    return vec3(v[0] / val, v[1] / val, v[2] / val);
}

#endif