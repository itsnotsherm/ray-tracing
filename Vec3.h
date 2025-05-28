#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3{
public:
	Vec3();
	Vec3(double x, double y, double z);

	double x() const { return m_x; }
	double y() const { return m_y; }
	double z() const { return m_z; }

	// Vector member functions
	Vec3 operator-() const;
	Vec3 operator+=(const Vec3& v);
	Vec3 operator*=(const Vec3& v);
	Vec3 operator/=(const Vec3& v);
	const double length() const;
	const double length_squared() const;

private:
	double m_x{};
	double m_y{};
	double m_z{};

};

// Point3 is an alias for Vec3, useful for geometric clarity in code
using Point3 = Vec3;

// Vector Utility functions

std::ostream& operator<<(std::ostream& out, const Vec3& v);
Vec3 operator+(const Vec3& u, const Vec3& v);
Vec3 operator-(const Vec3& u, const Vec3& v);
Vec3 operator*(const Vec3& u, const Vec3& v);
Vec3 operator*(double t, const Vec3& v);
Vec3 operator*(const Vec3& v, double t);
Vec3 operator/(const Vec3& v, double t);
double dot(const Vec3& u, const Vec3& v);
Vec3 cross(const Vec3& u, const Vec3& v);
Vec3 unit_vector(const Vec3& v);

#endif // !VEC3_H
