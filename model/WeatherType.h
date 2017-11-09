#pragma once

#ifndef _WEATHER_TYPE_H_
#define _WEATHER_TYPE_H_

namespace model {
    enum class WeatherType {
        _UNKNOWN_ = -1,
        CLEAR = 0,
        CLOUD = 1,
        RAIN = 2,
        _COUNT_ = 3
    };
}

#endif
