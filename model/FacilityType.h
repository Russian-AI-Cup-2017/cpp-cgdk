#pragma once

#ifndef _FACILITY_TYPE_H_
#define _FACILITY_TYPE_H_

namespace model {
    enum FacilityType {
        _FACILITY_UNKNOWN_ = -1,
        FACILITY_CONTROL_CENTER = 0,
        FACILITY_VEHICLE_FACTORY = 1,
        _FACILITY_COUNT_ = 2
    };
}

#endif
