#include "Facility.h"

using namespace model;

Facility::Facility()
    : id(-1), type(FacilityType::_UNKNOWN_), ownerPlayerId(-1), left(-1.0), top(-1.0), capturePoints(-1.0),
    vehicleType(VehicleType::_UNKNOWN_), productionProgress(-1) { }

Facility::Facility(long long id, FacilityType type, long long ownerPlayerId, double left, double top,
    double capturePoints, VehicleType vehicleType, int productionProgress)
    : id(id), type(type), ownerPlayerId(ownerPlayerId), left(left), top(top), capturePoints(capturePoints),
    vehicleType(vehicleType), productionProgress(productionProgress) { }

long long Facility::getId() const {
    return id;
}

FacilityType Facility::getType() const {
    return type;
}

long long Facility::getOwnerPlayerId() const {
    return ownerPlayerId;
}

double Facility::getLeft() const {
    return left;
}

double Facility::getTop() const {
    return top;
}

double Facility::getCapturePoints() const {
    return capturePoints;
}

VehicleType Facility::getVehicleType() const {
    return vehicleType;
}

int Facility::getProductionProgress() const {
    return productionProgress;
}
