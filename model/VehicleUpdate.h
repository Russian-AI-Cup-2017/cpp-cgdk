#pragma once

#ifndef _VEHICLE_UPDATE_H_
#define _VEHICLE_UPDATE_H_

#include <vector>

namespace model {
    class VehicleUpdate {
    private:
        long long id;
        double x;
        double y;
        int durability;
        int remainingAttackCooldownTicks;
        bool selected;
        std::vector<int> groups;
    public:
        VehicleUpdate();
        VehicleUpdate(long long id, double x, double y, int durability, int remainingAttackCooldownTicks, bool selected,
                const std::vector<int>& groups);

        long long getId() const;
        double getX() const;
        double getY() const;
        int getDurability() const;
        int getRemainingAttackCooldownTicks() const;
        bool isSelected() const;
        const std::vector<int>& getGroups() const;
    };
}

#endif
