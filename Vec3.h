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
	const double length();

private:
	double m_x;
	double m_y;
	double m_z;

};

// point3 is an alias for Vec3, useful for geometric clarity in code
using point3 = Vec3;

// Vector Utility functions

inline std::ostream& operator<<(std::ostream& out, Vec3& v);
inline Vec3 operator+(Vec3& u, Vec3& v);
inline Vec3 operator-(Vec3& u, Vec3& v);
inline Vec3 operator*(Vec3& u, Vec3& v);
inline Vec3 operator*(double t, Vec3& v);
inline Vec3 operator*(Vec3& v, double t);
inline Vec3 operator/(Vec3& v, double t);
inline double dot(Vec3& u, Vec3& v);
inline Vec3 cross(Vec3& u, Vec3& v);
inline Vec3 unit_vector(Vec3& v);

#endif // !VEC3_H
