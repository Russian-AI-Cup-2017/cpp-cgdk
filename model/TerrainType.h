#pragma once

#ifndef _TERRAIN_TYPE_H_
#define _TERRAIN_TYPE_H_

namespace model {
    enum class TerrainType {
        _UNKNOWN_ = -1,
        PLAIN = 0,
        SWAMP = 1,
        FOREST = 2,
        _COUNT_ = 3
    };
}

#endif
