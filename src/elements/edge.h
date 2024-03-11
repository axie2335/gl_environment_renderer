#ifndef EDGE_H
#define EDGE_H

#include "vec3.h"

class Edge {
public:
    Edge(Vec3 &v1, Vec3 &v2) : v1(v1), v2(v2) {};
private:
    Vec3 &v1;
    Vec3 &v2;
};


#endif