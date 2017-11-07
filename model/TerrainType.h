#pragma once

#ifndef _TERRAIN_TYPE_H_
#define _TERRAIN_TYPE_H_

namespace model {
    enum TerrainType {
        _TERRAIN_UNKNOWN_ = -1,
        TERRAIN_PLAIN = 0,
        TERRAIN_SWAMP = 1,
        TERRAIN_FOREST = 2,
        _TERRAIN_COUNT_ = 3
    };
}

#endif
