#pragma once

#ifndef _ACTION_TYPE_H_
#define _ACTION_TYPE_H_

namespace model {
    enum class ActionType {
        _UNKNOWN_ = -1,
        NONE = 0,
        CLEAR_AND_SELECT = 1,
        ADD_TO_SELECTION = 2,
        DESELECT = 3,
        ASSIGN = 4,
        DISMISS = 5,
        DISBAND = 6,
        MOVE = 7,
        ROTATE = 8,
        SCALE = 9,
        SETUP_VEHICLE_PRODUCTION = 10,
        TACTICAL_NUCLEAR_STRIKE = 11,
        _COUNT_ = 12
    };
}

#endif
