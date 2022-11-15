#pragma once

#include "vec3.h"

class Ray {
    public:
        vec3 o;
        vec3 d;
        Ray () {}
        Ray (const vec3& orig, const vec3& direction) {
            o = orig;
            d = direction;
        }
        vec3 origin() const { return o; }
        vec3 dir() const { return d; }
        vec3 at(double t) const {
            return o + t*d;
        }

};