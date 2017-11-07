#pragma once

#ifndef _FACILITY_H_
#define _FACILITY_H_

#include "FacilityType.h"
#include "VehicleType.h"

namespace model {
    class Facility {
    private:
        long long id;
        FacilityType type;
        long long ownerPlayerId;
        double left;
        double top;
        double capturePoints;
        VehicleType vehicleType;
        int productionProgress;
    public:
        Facility();
        Facility(long long id, FacilityType type, long long ownerPlayerId, double left, double top,
                double capturePoints, VehicleType vehicleType, int productionProgress);

        long long getId() const;
        FacilityType getType() const;
        long long getOwnerPlayerId() const;
        double getLeft() const;
        double getTop() const;
        double getCapturePoints() const;
        VehicleType getVehicleType() const;
        int getProductionProgress() const;
    };
}

#endif
