#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class ray {
public:
	ray() = default;

	ray(const point3& origin, const vec3& direction)
		: m_origin{ origin }, m_direction{ direction }
	{
	}

	const point3& origin() const { return m_origin; }
	const vec3& direction() const { return m_direction; }

	// P(t) = A + tB, where P is a 3D position along a line in 3D
	point3 at(double t) const {
		return m_origin + t * m_direction;
	}

private:
	point3 m_origin{};
	vec3 m_direction{};
};


#endif // !RAY_H