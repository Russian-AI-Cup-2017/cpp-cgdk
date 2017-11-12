#pragma once

#ifndef _MOVE_H_
#define _MOVE_H_

#include "ActionType.h"
#include "VehicleType.h"

namespace model {
    class Move {
    private:
        ActionType action;
        int group;
        double left;
        double top;
        double right;
        double bottom;
        double x;
        double y;
        double angle;
        double factor;
        double maxSpeed;
        double maxAngularSpeed;
        VehicleType vehicleType;
        long long facilityId;
        long long vehicleId;
    public:
        Move();

        ActionType getAction() const;
        void setAction(const ActionType action);
        int getGroup() const;
        void setGroup(const int group);
        double getLeft() const;
        void setLeft(const double left);
        double getTop() const;
        void setTop(const double top);
        double getRight() const;
        void setRight(const double right);
        double getBottom() const;
        void setBottom(const double bottom);
        double getX() const;
        void setX(const double x);
        double getY() const;
        void setY(const double y);
        double getAngle() const;
        void setAngle(const double angle);
        double getFactor() const;
        void setFactor(const double factor);
        double getMaxSpeed() const;
        void setMaxSpeed(const double maxSpeed);
        double getMaxAngularSpeed() const;
        void setMaxAngularSpeed(const double maxAngularSpeed);
        VehicleType getVehicleType() const;
        void setVehicleType(const VehicleType vehicleType);
        long long getFacilityId() const;
        void setFacilityId(const long long facilityId);
        long long getVehicleId() const;
        void setVehicleId(const long long vehicleId);
    };
}

#endif
