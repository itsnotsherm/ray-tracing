#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class ray {
public:
	ray() = default;

	ray(const Point3& origin, const Vec3& direction)
		: m_origin{ origin }, m_direction{ direction }
	{
	}

	const Point3& origin() const { return m_origin; }
	const Vec3& direction() const { return m_direction; }

	// P(t) = A + tB, where P is a 3D position along a line in 3D
	Point3 at(double t) const {
		return m_origin + t * m_direction;
	}

private:
	Point3 m_origin{};
	Vec3 m_direction{};
};


#endif // !RAY_H