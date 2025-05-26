#include "Vec3.h"
#include <cmath>

Vec3::Vec3() = default;
Vec3::Vec3(double x, double y, double z)
	: m_x{ x }, m_y{ y }, m_z{ z }
{
}

Vec3 Vec3::operator-() const {
	return Vec3(-x(), -y(), -z());
}

Vec3 Vec3::operator+=(const Vec3& v) {
	return Vec3(x() + v.x(),
		y() + v.y(),
		z() + v.z());
}

Vec3 Vec3::operator*=(const Vec3& v) {
	return Vec3(x() * v.x(),
		y() * v.y(),
		z() * v.z());
}

Vec3 Vec3::operator/=(const Vec3& v) {
	return Vec3(x() / v.x(),
		y() / v.y(),
		z() / v.z());
}

const double Vec3::length() {
	return std::sqrt((x() * x()
		+ y() * y()
		+ z() * z()));
}

inline std::ostream& operator<<(std::ostream& out, Vec3& v) {
	out << v.x() << " " << v.y() << " " << v.z();
	return out;
}

inline Vec3 operator+(Vec3& u, Vec3& v) {
	return Vec3(u.x() + v.x(),
		u.y() + v.y(),
		u.z() + v.z());
}

inline Vec3 operator-(Vec3& u, Vec3& v) {
	return Vec3(u.x() - v.x(),
		u.y() - v.y(),
		u.z() - v.z());
}

inline Vec3 operator*(Vec3& u, Vec3& v) {
	return Vec3(u.x() * v.x(),
		u.y() * v.y(),
		u.z() * v.z());
}

inline Vec3 operator*(double t, Vec3& v) {
	return Vec3(t * v.x(),
		t * v.y(),
		t * v.z());
}
inline Vec3 operator*(Vec3& v, double t) {
	return t * v;
}

inline Vec3 operator/(Vec3& v, double t) {
	return (1 / t) * v;
}

inline double dot(Vec3& u, Vec3& v) {
	return (u.x() * v.x()
		+ u.y() * v.y()
		+ u.z() * v.z());
}

inline Vec3 cross(Vec3& u, Vec3& v) {
	return Vec3(u.y() * v.z() - u.z() * v.y(),
		u.z() * v.x() - u.x() * v.z(),
		u.x() * v.y() - u.y() * v.x());
}

inline Vec3 unit_vector(Vec3& v) {
	return v / v.length();
}