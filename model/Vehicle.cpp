#include "Vehicle.h"
#include "VehicleUpdate.h"

using namespace model;
using namespace std;

Vehicle::Vehicle()
    : CircularUnit(0, 0.0, 0.0, 0.0), playerId(-1), durability(-1), maxDurability(-1), maxSpeed(-1.0),
    visionRange(-1.0), squaredVisionRange(-1.0), groundAttackRange(-1.0), squaredGroundAttackRange(-1.0),
    aerialAttackRange(-1.0), squaredAerialAttackRange(-1.0), groundDamage(-1), aerialDamage(-1), groundDefence(-1),
    aerialDefence(-1), attackCooldownTicks(-1), remainingAttackCooldownTicks(-1), type(VehicleType::_UNKNOWN_),
    aerial(false), selected(false), groups(vector<int>()) { }

Vehicle::Vehicle(long long id, double x, double y, double radius, long long playerId, int durability, int maxDurability,
    double maxSpeed, double visionRange, double squaredVisionRange, double groundAttackRange,
    double squaredGroundAttackRange, double aerialAttackRange, double squaredAerialAttackRange, int groundDamage,
    int aerialDamage, int groundDefence, int aerialDefence, int attackCooldownTicks, int remainingAttackCooldownTicks,
    VehicleType type, bool aerial, bool selected, const vector<int>& groups)
    : CircularUnit(id, x, y, radius), playerId(playerId), durability(durability), maxDurability(maxDurability),
    maxSpeed(maxSpeed), visionRange(visionRange), squaredVisionRange(squaredVisionRange),
    groundAttackRange(groundAttackRange), squaredGroundAttackRange(squaredGroundAttackRange),
    aerialAttackRange(aerialAttackRange), squaredAerialAttackRange(squaredAerialAttackRange),
    groundDamage(groundDamage), aerialDamage(aerialDamage), groundDefence(groundDefence), aerialDefence(aerialDefence),
    attackCooldownTicks(attackCooldownTicks), remainingAttackCooldownTicks(remainingAttackCooldownTicks), type(type),
    aerial(aerial), selected(selected), groups(groups) { }

Vehicle::Vehicle(const Vehicle& vehicle, const VehicleUpdate& vehicleUpdate)
    : CircularUnit(vehicle.getId(), vehicleUpdate.getX(), vehicleUpdate.getY(), vehicle.getRadius()),
    playerId(vehicle.getPlayerId()), durability(vehicleUpdate.getDurability()),
    maxDurability(vehicle.getMaxDurability()), maxSpeed(vehicle.getMaxSpeed()), visionRange(vehicle.getVisionRange()),
    squaredVisionRange(vehicle.getSquaredVisionRange()), groundAttackRange(vehicle.getGroundAttackRange()),
    squaredGroundAttackRange(vehicle.getSquaredGroundAttackRange()), aerialAttackRange(vehicle.getAerialAttackRange()),
    squaredAerialAttackRange(vehicle.getSquaredAerialAttackRange()), groundDamage(vehicle.getGroundDamage()),
    aerialDamage(vehicle.getAerialDamage()), groundDefence(vehicle.getGroundDefence()),
    aerialDefence(vehicle.getAerialDefence()), attackCooldownTicks(vehicle.getAttackCooldownTicks()),
    remainingAttackCooldownTicks(vehicleUpdate.getRemainingAttackCooldownTicks()), type(vehicle.getType()),
    aerial(vehicle.isAerial()), selected(vehicleUpdate.isSelected()), groups(vehicleUpdate.getGroups()) { }

long long Vehicle::getPlayerId() const {
    return playerId;
}

int Vehicle::getDurability() const {
    return durability;
}

int Vehicle::getMaxDurability() const {
    return maxDurability;
}

double Vehicle::getMaxSpeed() const {
    return maxSpeed;
}

double Vehicle::getVisionRange() const {
    return visionRange;
}

double Vehicle::getSquaredVisionRange() const {
    return squaredVisionRange;
}

double Vehicle::getGroundAttackRange() const {
    return groundAttackRange;
}

double Vehicle::getSquaredGroundAttackRange() const {
    return squaredGroundAttackRange;
}

double Vehicle::getAerialAttackRange() const {
    return aerialAttackRange;
}

double Vehicle::getSquaredAerialAttackRange() const {
    return squaredAerialAttackRange;
}

int Vehicle::getGroundDamage() const {
    return groundDamage;
}

int Vehicle::getAerialDamage() const {
    return aerialDamage;
}

int Vehicle::getGroundDefence() const {
    return groundDefence;
}

int Vehicle::getAerialDefence() const {
    return aerialDefence;
}

int Vehicle::getAttackCooldownTicks() const {
    return attackCooldownTicks;
}

int Vehicle::getRemainingAttackCooldownTicks() const {
    return remainingAttackCooldownTicks;
}

VehicleType Vehicle::getType() const {
    return type;
}

bool Vehicle::isAerial() const {
    return aerial;
}

bool Vehicle::isSelected() const {
    return selected;
}

const vector<int>& Vehicle::getGroups() const {
    return groups;
}
