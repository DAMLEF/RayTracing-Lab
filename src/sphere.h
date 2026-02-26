#ifndef SPHERE_H
#define SPHERE_H

# include "hittable.h"


class sphere: public hittable {
 private:
    point3 center;
    double radius;
 public:
    sphere(const point3& center, double radius): center(center), radius(std::fmax(0, radius)) {}

    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override {
        vec3 oc = center - r.origin();

        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);        // We use the simplification h = -2b to speed up the calculations.
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h * h - a * c;

        if(discriminant < 0) {
            return false;
        }

        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd)/a;

        if(root <= ray_tmin || ray_tmax <= root) {
            root = (h + sqrtd)/a;

            if(root <= ray_tmin || ray_tmax <= root) {
                return false;
            }
        }

        // We are building the record to have the contact normal info
        rec.t = root;
        rec.p = center;
        rec.normal = (rec.p - center) / radius;

        return true;

    }


};

#endif //SPHERE_H
