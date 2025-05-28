#include "Sphere.h"

Sphere::Sphere(const Point3& center, double radius)
	: m_center{ center }, m_radius{ radius }
{
}

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override {
    Vec3 oc = center() - r.origin(); // origin (of ray) to center
    Vec3 d = r.direction();

    // coefficients of quadratic formula
    auto a = dot(d, d);
    auto b = -2 * dot(d, oc);
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    
    auto sqrt_discriminant = std::sqrt(discriminant);

    // Find nearest root that lies within acceptable range
    auto root = (-b - sqrt_discriminant) / (2.0 * a);
    if (!isWithinRange(root, t_min, t_max)) {
        root = (-b + sqrt_discriminant) / (2.0 * a);

        if (!isWithinRange(root, t_min, t_max)) return false;
    }

    rec.p = r.at(root);
    rec.normal = (rec.p - center()) / radius();
    rec.t = root;

    return true;
}

bool isWithinRange(const double t, const double t_min, const double t_max) {
    return (t_min < t) && (t < t_max);
}