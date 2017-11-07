#pragma once

#ifndef _PLAYER_CONTEXT_H_
#define _PLAYER_CONTEXT_H_

#include "Player.h"
#include "World.h"

namespace model {
    class PlayerContext {
    private:
        Player player;
        World world;
    public:
        PlayerContext();
        PlayerContext(const Player& player, const World& world);

        const Player& getPlayer() const;
        const World& getWorld() const;
    };
}

#endif
