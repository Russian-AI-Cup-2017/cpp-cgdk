#pragma once

#ifndef _ACTION_TYPE_H_
#define _ACTION_TYPE_H_

namespace model {
    enum ActionType {
        _ACTION_UNKNOWN_ = -1,
        ACTION_NONE = 0,
        ACTION_CLEAR_AND_SELECT = 1,
        ACTION_ADD_TO_SELECTION = 2,
        ACTION_DESELECT = 3,
        ACTION_ASSIGN = 4,
        ACTION_DISMISS = 5,
        ACTION_DISBAND = 6,
        ACTION_MOVE = 7,
        ACTION_ROTATE = 8,
        ACTION_SETUP_VEHICLE_PRODUCTION = 9,
        _ACTION_COUNT_ = 10
    };
}

#endif
