#include "Player.h"

using namespace model;

Player::Player()
    : id(-1), me(false), strategyCrashed(false), score(-1), remainingActionCooldownTicks(-1) { }

Player::Player(long long id, bool me, bool strategyCrashed, int score, int remainingActionCooldownTicks)
    : id(id), me(me), strategyCrashed(strategyCrashed), score(score),
    remainingActionCooldownTicks(remainingActionCooldownTicks) { }

long long Player::getId() const {
    return id;
}

bool Player::isMe() const {
    return me;
}

bool Player::isStrategyCrashed() const {
    return strategyCrashed;
}

int Player::getScore() const {
    return score;
}

int Player::getRemainingActionCooldownTicks() const {
    return remainingActionCooldownTicks;
}
