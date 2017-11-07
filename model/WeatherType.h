#pragma once

#ifndef _WEATHER_TYPE_H_
#define _WEATHER_TYPE_H_

namespace model {
    enum WeatherType {
        _WEATHER_UNKNOWN_ = -1,
        WEATHER_CLEAR = 0,
        WEATHER_CLOUD = 1,
        WEATHER_RAIN = 2,
        _WEATHER_COUNT_ = 3
    };
}

#endif
