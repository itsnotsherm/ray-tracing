#include "Sphere.h"

Sphere::Sphere(const Point3& center, double radius)
	: m_center{ center }, m_radius{ radius }
{
}

bool Sphere::hit(const Ray& r, Interval ray_t, HitRecord& rec) const {
    Vec3 oc = center() - r.origin(); // origin (of ray) to center
    Vec3 d = r.direction();

    // coefficients of quadratic formula
    auto a = dot(d, d);
    auto b = -2 * dot(d, oc);
    auto c = dot(oc, oc) - radius() * radius();
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    
    auto sqrt_discriminant = std::sqrt(discriminant);

    // Find nearest root that lies within acceptable range
    auto root = (-b - sqrt_discriminant) / (2.0 * a);
    if (!ray_t.surrounds(root)) {
        root = (-b + sqrt_discriminant) / (2.0 * a);

        if (!ray_t.surrounds(root)) return false;
    }

    rec.set_t(root);
    rec.set_p(r.at(rec.t()));
    
    Vec3 outward_normal = (rec.p() - center()) / radius();
    rec.set_face_normal(r, outward_normal);

    return true;
}

bool isWithinRange(const double t, const double t_min, const double t_max) {
    return (t_min < t) && (t < t_max);
}