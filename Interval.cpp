#include "Interval.h"

const Interval Interval::empty = Interval();
const Interval Interval::universe = Interval(-infinity, infinity);

Interval::Interval() = default;
Interval::Interval(double min, double max) : m_min(min), m_max(max) {}

double Interval::size() const {
	return max() - min();
}

bool Interval::contains(double value) const {
	return (min() <= value) && (value <= max());
}

bool Interval::surrounds(double value) const {
	return (min() < value) && (value < max());
}