#pragma once

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <vector>

#include "CircularUnit.h"
#include "VehicleUpdate.h"
#include "VehicleType.h"

namespace model {
    class Vehicle : public CircularUnit {
    private:
        long long playerId;
        int durability;
        int maxDurability;
        double maxSpeed;
        double visionRange;
        double squaredVisionRange;
        double groundAttackRange;
        double squaredGroundAttackRange;
        double aerialAttackRange;
        double squaredAerialAttackRange;
        int groundDamage;
        int aerialDamage;
        int groundDefence;
        int aerialDefence;
        int attackCooldownTicks;
        int remainingAttackCooldownTicks;
        VehicleType type;
        bool aerial;
        bool selected;
        std::vector<int> groups;
    public:
        Vehicle();
        Vehicle(long long id, double x, double y, double radius, long long playerId, int durability, int maxDurability,
                double maxSpeed, double visionRange, double squaredVisionRange, double groundAttackRange,
                double squaredGroundAttackRange, double aerialAttackRange, double squaredAerialAttackRange,
                int groundDamage, int aerialDamage, int groundDefence, int aerialDefence, int attackCooldownTicks,
                int remainingAttackCooldownTicks, VehicleType type, bool aerial, bool selected,
                const std::vector<int>& groups);
        Vehicle(const Vehicle& vehicle, const VehicleUpdate& vehicleUpdate);

        long long getPlayerId() const;
        int getDurability() const;
        int getMaxDurability() const;
        double getMaxSpeed() const;
        double getVisionRange() const;
        double getSquaredVisionRange() const;
        double getGroundAttackRange() const;
        double getSquaredGroundAttackRange() const;
        double getAerialAttackRange() const;
        double getSquaredAerialAttackRange() const;
        int getGroundDamage() const;
        int getAerialDamage() const;
        int getGroundDefence() const;
        int getAerialDefence() const;
        int getAttackCooldownTicks() const;
        int getRemainingAttackCooldownTicks() const;
        VehicleType getType() const;
        bool isAerial() const;
        bool isSelected() const;
        const std::vector<int>& getGroups() const;
    };
}

#endif
