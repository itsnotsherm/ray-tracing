#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"

class Sphere : public Hittable {
public:
	Sphere(const Point3& center, double radius);

	const Point3& center() const { return m_center; }
	double radius() const { return m_radius; }

	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

private:
	Point3 m_center{};
	double m_radius{};
};

bool isWithinRange(const double t, const double t_min, const double t_max);

#endif