#pragma once

#include "hittable.h"
#include "vec3.h"

class Sphere : public Hittable {
    public:
        vec3 center;
        double radius;

        Sphere() {}
        Sphere(vec3 cen, double r) : center(cen), radius(r) {};

        virtual bool hit(const Ray& r, double t_min, double t_max,
                        hit_record& rec) const override;
};

bool Sphere::hit(const Ray& ray, double t_min, double t_max,
                                            hit_record& record) const {
    //https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer
    //-rendering-simple-shapes/ray-sphere-intersection
    vec3 oc = ray.origin() - center;
    //|O + tD|**2 - R**2 = 0    equation for point on sphere
    //D**2t**2 + 2ODt + (O**2-R**2) = 0
    //f(x) = ax**2 + bx + c
    auto a = ray.dir().len_squared();           //D**2
    auto half_b = dot(oc, ray.dir());           //OD
    auto c = oc.len_squared() - radius*radius;  //O**2 - R**2

    // quadratic formula x = (-b +- sqrt(b**2 - 4ac))/2a
    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) { return false; }
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    record.t = root;
    record.p = ray.at(record.t);
    vec3 outward_normal = (record.p - center) / radius;
    record.set_face_normal(ray, outward_normal);
    return true;
}