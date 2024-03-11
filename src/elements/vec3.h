#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <cstddef>

class Vec3 {
public:
    Vec3() : v{0, 0, 0} {};
    Vec3(double v1, double v2, double v3) : v{v1, v2, v3} {};
    
    static size_t get_offset() {
        return offsetof(Vec3, v);
    }
    
    double operator[](int i) const { return v[i]; };
    double &operator[](int i) { return v[i]; };
    Vec3 operator-() { return Vec3{-v[0], -v[1], -v[2]}; };

    Vec3 &operator+=(const Vec3 &vec) { 
        v[0] += vec[0];
        v[1] += vec[1];
        v[2] += vec[2];
        return *this; 
    };

    Vec3 &operator-=(const Vec3 &vec) { 
        v[0] -= vec[0];
        v[1] -= vec[1];
        v[2] -= vec[2];
        return *this; 
    };

    Vec3 &operator*=(double val) {
        v[0] *= val;
        v[1] *= val;
        v[2] *= val;
        return *this;
    }

    Vec3 &operator/=(double val) {
        v[0] /= val;
        v[1] /= val;
        v[2] /= val;
        return *this;
    }

    Vec3 &operator*=(const Vec3 &vec) {
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

    Vec3 unit_vector() {
        double length = this->length();
        return Vec3(v[0] / length, v[1] / length, v[2] / length);
    }

private:
    double v[3];
};

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline Vec3 operator*(const Vec3 &v, const Vec3 &u) {
    return Vec3(v[0] * u[0], v[1] * u[1], v[2] * u[2]);
}

inline Vec3 operator*(const Vec3 &v, double val) {
    return Vec3(v[0] * val, v[1] * val, v[2] * val);
}

inline Vec3 operator*(double val, const Vec3 &v) {
    return Vec3(v[0] * val, v[1] * val, v[2] * val);
}

inline Vec3 operator/(const Vec3 &v, double val) {
    return Vec3(v[0] / val, v[1] / val, v[2] / val);
}

#endif