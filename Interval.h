#ifndef INTERVAL_H
#define INTERVAL_H

#include "Utils.h"

class Interval {
public:
	Interval();
	Interval(double min, double max);

	const double min() const { return m_min; }
	const double max() const { return m_max; }

	double size() const;
	bool contains(double value) const;
	bool surrounds(double value) const;

	static const Interval empty;
	static const Interval universe;

private:
	double m_min{ +infinity };
	double m_max{ -infinity };
};

#endif // INTERVAL_H