#ifndef UTILS_H
#define UTILS_H

#define _USE_MATH_DEFINES

#include <cmath>
#include <limits>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = M_PI;

// Utility Functions
double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

// Common Headers
#include "Color.h"
#include "Ray.h"
#include "Vec3.h"

#endif