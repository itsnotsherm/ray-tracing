#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

// Common Headers
#include "Color.h"
#include "Interval.h"
#include "Ray.h"
#include "Vec3.h"

#endif