#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
    public:
    double arr[3];

    vec3() : arr{0,0,0} {}
    vec3(double x, double y, double z) : arr{x,y,z} {}

    inline double x () const { return arr[0]; }
    inline double y () const { return arr[1]; }
    inline double z () const { return arr[2]; }
    inline double r () const { return arr[0]; }
    inline double g () const { return arr[1]; }
    inline double b () const { return arr[2]; }

    
    inline double operator [] (int i) const { return arr[i]; }
    inline double& operator [] (int i) {return arr[i]; }

    //Addition
    inline vec3& operator += (const vec3 &vec) {
        arr[0] += vec.arr[0];
        arr[1] += vec.arr[1];
        arr[2] += vec.arr[2];
        return *this;
    }

    //Subtraction
    inline vec3 operator - () const { return vec3(-arr[0], -arr[1], -arr[2]); }
    inline vec3& operator -= (const vec3 &vec) {
        arr[0] -= vec.arr[0];
        arr[1] -= vec.arr[1];
        arr[2] -= vec.arr[2];
        return *this;
    }

    //Multiplication
    inline vec3& operator *= (const double t) {
        arr[0] *= t;
        arr[1] *= t;
        arr[2] *= t;
        return *this;
    }

    //Division
    inline vec3& operator *= (const vec3 &vec) {
        arr[0] *= vec.arr[0];
        arr[1] *= vec.arr[1];
        arr[2] *= vec.arr[2];
    }

    //Vector divide by scalar
    inline vec3& operator /= (const double t) { return *this *= 1/t; }

    inline double length() const { return sqrt(arr[0]*arr[0] + arr[1]*arr[1] + arr[2]*arr[2]); }
    inline double len_squared() { return arr[0]*arr[0] + arr[1]*arr[1] + arr[2]*arr[2]; }
};


inline double dot(const vec3 &vec_1, const vec3 &vec_2) {
    return  vec_1.arr[0] * vec_2.arr[0] + 
            vec_1.arr[1] * vec_2.arr[1] +
            vec_1.arr[2] * vec_2.arr[2];
}
inline vec3 cross(const vec3 &vec_1, const vec3 &vec_2) {
    return vec3((vec_1.arr[1]*vec_2.arr[2] - vec_1.arr[2]*vec_2.arr[1]),
                (vec_1.arr[2]*vec_2.arr[0] - vec_1.arr[0]*vec_2.arr[2]),
                (vec_1.arr[0]*vec_2.arr[1] - vec_1.arr[1]*vec_2.arr[0]));
}
inline std::ostream& operator<<(std::ostream &out, const vec3 &vec) {
    return out << vec.arr[0] << ' ' << vec.arr[1] << ' ' << vec.arr[2];
}
inline vec3 operator + (const vec3 &vec_1, const vec3 &vec_2) {
    return vec3(vec_1.arr[0] + vec_2.arr[0],
                vec_1.arr[1] + vec_2.arr[1],
                vec_1.arr[2] + vec_2.arr[2]);
}
inline vec3 operator - (const vec3 &vec_1, const vec3 &vec_2) {
    return vec3(vec_1.arr[0] - vec_2.arr[0],
                vec_1.arr[1] - vec_2.arr[1],
                vec_1.arr[2] - vec_2.arr[2]);
}
inline vec3 operator * (const vec3 &vec_1, const vec3 &vec_2) {
    return vec3(vec_1.arr[0] * vec_2.arr[0],
                vec_1.arr[1] * vec_2.arr[1],
                vec_1.arr[2] * vec_2.arr[2]);
}
inline vec3 operator * (double t, const vec3 &vec) {
    return vec3(t * vec.arr[0],
                t * vec.arr[1],
                t * vec.arr[2]);
}
inline vec3 operator * (const vec3 &vec, double t) { return t * vec; }
inline vec3 operator / (vec3 vec, double t) { return (1/t) * vec; }
inline vec3 unit_vector(vec3 vec) { return vec / vec.length(); }


#endif //VEC3_H