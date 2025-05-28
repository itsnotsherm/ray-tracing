#include "HitRecord.h"

void HitRecord::set_p(const Point3& p) {
	m_p = p;
}

void HitRecord::set_normal(const Vec3& normal) {
	m_normal = normal;
}

void HitRecord::set_t(const double t) {
	m_t = t;
}

void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
	// Sets hit record normal vector, we assume outward_normal has unit length
	m_front_face = dot(r.direction(), outward_normal) < 0;
	set_normal((m_front_face) ? outward_normal : -outward_normal);
}