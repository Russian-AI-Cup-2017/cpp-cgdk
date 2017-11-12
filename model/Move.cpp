#include "Move.h"

using namespace model;

Move::Move()
    : action(ActionType::_UNKNOWN_), group(0), left(0.0), top(0.0), right(0.0), bottom(0.0), x(0.0), y(0.0), angle(0.0),
    factor(0.0), maxSpeed(0.0), maxAngularSpeed(0.0), vehicleType(VehicleType::_UNKNOWN_), facilityId(-1),
    vehicleId(-1) { }

ActionType Move::getAction() const {
    return action;
}

void Move::setAction(const ActionType action) {
    this->action = action;
}

int Move::getGroup() const {
    return group;
}

void Move::setGroup(const int group) {
    this->group = group;
}

double Move::getLeft() const {
    return left;
}

void Move::setLeft(const double left) {
    this->left = left;
}

double Move::getTop() const {
    return top;
}

void Move::setTop(const double top) {
    this->top = top;
}

double Move::getRight() const {
    return right;
}

void Move::setRight(const double right) {
    this->right = right;
}

double Move::getBottom() const {
    return bottom;
}

void Move::setBottom(const double bottom) {
    this->bottom = bottom;
}

double Move::getX() const {
    return x;
}

void Move::setX(const double x) {
    this->x = x;
}

double Move::getY() const {
    return y;
}

void Move::setY(const double y) {
    this->y = y;
}

double Move::getAngle() const {
    return angle;
}

void Move::setAngle(const double angle) {
    this->angle = angle;
}

double Move::getFactor() const {
    return factor;
}

void Move::setFactor(const double factor) {
    this->factor = factor;
}

double Move::getMaxSpeed() const {
    return maxSpeed;
}

void Move::setMaxSpeed(const double maxSpeed) {
    this->maxSpeed = maxSpeed;
}

double Move::getMaxAngularSpeed() const {
    return maxAngularSpeed;
}

void Move::setMaxAngularSpeed(const double maxAngularSpeed) {
    this->maxAngularSpeed = maxAngularSpeed;
}

VehicleType Move::getVehicleType() const {
    return vehicleType;
}

void Move::setVehicleType(const VehicleType vehicleType) {
    this->vehicleType = vehicleType;
}

long long Move::getFacilityId() const {
    return facilityId;
}

void Move::setFacilityId(const long long facilityId) {
    this->facilityId = facilityId;
}

long long Move::getVehicleId() const {
    return vehicleId;
}

void Move::setVehicleId(const long long vehicleId) {
    this->vehicleId = vehicleId;
}
