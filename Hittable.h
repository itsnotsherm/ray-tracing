#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"

class Hittable {
public:
	virtual ~Hittable() = default;

	virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

#endif