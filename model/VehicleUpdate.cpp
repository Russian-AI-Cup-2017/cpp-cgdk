#include "VehicleUpdate.h"

using namespace model;
using namespace std;

VehicleUpdate::VehicleUpdate()
    : id(-1), x(-1.0), y(-1.0), durability(-1), remainingAttackCooldownTicks(-1), selected(false),
    groups(vector<int>()) { }

VehicleUpdate::VehicleUpdate(long long id, double x, double y, int durability, int remainingAttackCooldownTicks,
    bool selected, const vector<int>& groups)
    : id(id), x(x), y(y), durability(durability), remainingAttackCooldownTicks(remainingAttackCooldownTicks),
    selected(selected), groups(groups) { }

long long VehicleUpdate::getId() const {
    return id;
}

double VehicleUpdate::getX() const {
    return x;
}

double VehicleUpdate::getY() const {
    return y;
}

int VehicleUpdate::getDurability() const {
    return durability;
}

int VehicleUpdate::getRemainingAttackCooldownTicks() const {
    return remainingAttackCooldownTicks;
}

bool VehicleUpdate::isSelected() const {
    return selected;
}

const vector<int>& VehicleUpdate::getGroups() const {
    return groups;
}
