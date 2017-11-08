#include "Unit.h"

#define _USE_MATH_DEFINES

#include <cmath>

using namespace model;

Unit::Unit(long long id, double x, double y)
    : id(id), x(x), y(y) { }

long long Unit::getId() const {
    return id;
}

double Unit::getX() const {
    return x;
}

double Unit::getY() const {
    return y;
}

double Unit::getDistanceTo(double x, double y) const {
    double xRange = x - this->x;
    double yRange = y - this->y;
    return sqrt(xRange * xRange + yRange * yRange);
}

double Unit::getDistanceTo(const Unit& unit) const {
    return this->getDistanceTo(unit.x, unit.y);
}

double Unit::getSquaredDistanceTo(double x, double y) const {
    double xRange = x - this->x;
    double yRange = y - this->y;
    return xRange * xRange + yRange * yRange;
}

double Unit::getSquaredDistanceTo(const Unit& unit) const {
    return this->getSquaredDistanceTo(unit.x, unit.y);
}

Unit::~Unit() { }
