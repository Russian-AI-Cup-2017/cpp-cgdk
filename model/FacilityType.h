#pragma once

#ifndef _FACILITY_TYPE_H_
#define _FACILITY_TYPE_H_

namespace model {
    enum class FacilityType {
        _UNKNOWN_ = -1,
        CONTROL_CENTER = 0,
        VEHICLE_FACTORY = 1,
        _COUNT_ = 2
    };
}

#endif
