#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable {
public:
	HittableList();

	void add(std::shared_ptr<Hittable> object);
	void clear();

	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

private:
	std::vector<std::shared_ptr<Hittable>> m_objects;
};

#endif