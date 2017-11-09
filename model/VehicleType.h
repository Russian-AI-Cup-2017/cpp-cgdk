#pragma once

#ifndef _VEHICLE_TYPE_H_
#define _VEHICLE_TYPE_H_

namespace model {
    enum class VehicleType {
        _UNKNOWN_ = -1,
        ARRV = 0,
        FIGHTER = 1,
        HELICOPTER = 2,
        IFV = 3,
        TANK = 4,
        _COUNT_ = 5
    };
}

#endif
