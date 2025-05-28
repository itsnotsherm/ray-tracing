#ifndef HITRECORD_H
#define HITRECORD_H

#include "Ray.h"
#include "Vec3.h"

class HitRecord {
public:
	const Point3& p() const { return m_p; }
	const Vec3& normal() const { return m_normal; }
	double t() const { return m_t; }

	void set_p(const Point3& p);
	void set_t(const double t);
	void set_face_normal(const Ray& r, const Vec3& outward_normal);

private:
	Point3 m_p{};
	Vec3 m_normal{};
	double m_t{};
	bool m_front_face{};

	void set_normal(const Vec3& normal);
};

#endif
