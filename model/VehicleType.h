#pragma once

#ifndef _VEHICLE_TYPE_H_
#define _VEHICLE_TYPE_H_

namespace model {
    enum VehicleType {
        _VEHICLE_UNKNOWN_ = -1,
        VEHICLE_ARRV = 0,
        VEHICLE_FIGHTER = 1,
        VEHICLE_HELICOPTER = 2,
        VEHICLE_IFV = 3,
        VEHICLE_TANK = 4,
        _VEHICLE_COUNT_ = 5
    };
}

#endif
