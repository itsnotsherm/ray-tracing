#include "HittableList.h"

HittableList::HittableList() = default();

void HittableList::add(shared_ptr<Hittable> object) {
	m_objects.push_back(object);
}

void HittableList::clear() {
	objects.clear();
}

bool HittableList::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override {
	HitRecord temp_rec;
	bool hit_anything = false;
	auto closest_so_far = t_max;

	for (const auto& object : objects) {
		if (object->hit(r, t_min, closest_so_far, temp_rec)) {
			hit_anything = true;
			closest_so_far = temp_rec.t();
			rec = temp_rec;
		}
	}
	
	return hit_anything;
}