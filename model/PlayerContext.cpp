#include "PlayerContext.h"

using namespace model;

PlayerContext::PlayerContext()
    : player(Player()), world(World()) { }

PlayerContext::PlayerContext(const Player& player, const World& world)
    : player(player), world(world) { }

const Player& PlayerContext::getPlayer() const {
    return player;
}

const World& PlayerContext::getWorld() const {
    return world;
}
