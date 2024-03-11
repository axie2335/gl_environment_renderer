#ifndef EDGE_H
#define EDGE_H

#include "vec3.h"

class edge {
public:
    edge(vec3 &v1, vec3 &v2) : v1(v1), v2(v2) {};
private:
    vec3 &v1;
    vec3 &v2;
};







#endif