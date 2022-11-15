#pragma once

#include "ray.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

class camera {
    public:
    vec3 origin;
    vec3 bottom_left_corner;
    

    camera (vec3 look_from, vec3 look_at, vec3 up, double fov, double aspect_ratio,
            double aperture, float focus_dist) {
        

    }
};
