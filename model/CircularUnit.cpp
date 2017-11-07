#include "CircularUnit.h"

using namespace model;

CircularUnit::CircularUnit(long long id, double x, double y, double radius)
    : Unit(id, x, y), radius(radius) { }

double CircularUnit::getRadius() const {
    return radius;
}

CircularUnit::~CircularUnit() { }
