#include "Player.h"

using namespace model;

Player::Player()
    : id(-1), me(false), strategyCrashed(false), score(-1), remainingActionCooldownTicks(-1),
    remainingNuclearStrikeCooldownTicks(-1), nextNuclearStrikeVehicleId(-1), nextNuclearStrikeTickIndex(-1),
    nextNuclearStrikeX(-1.0), nextNuclearStrikeY(-1.0) { }

Player::Player(long long id, bool me, bool strategyCrashed, int score, int remainingActionCooldownTicks,
    int remainingNuclearStrikeCooldownTicks, long long nextNuclearStrikeVehicleId, int nextNuclearStrikeTickIndex,
    double nextNuclearStrikeX, double nextNuclearStrikeY)
    : id(id), me(me), strategyCrashed(strategyCrashed), score(score),
    remainingActionCooldownTicks(remainingActionCooldownTicks),
    remainingNuclearStrikeCooldownTicks(remainingNuclearStrikeCooldownTicks),
    nextNuclearStrikeVehicleId(nextNuclearStrikeVehicleId), nextNuclearStrikeTickIndex(nextNuclearStrikeTickIndex),
    nextNuclearStrikeX(nextNuclearStrikeX), nextNuclearStrikeY(nextNuclearStrikeY) { }

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

int Player::getRemainingNuclearStrikeCooldownTicks() const {
    return remainingNuclearStrikeCooldownTicks;
}

long long Player::getNextNuclearStrikeVehicleId() const {
    return nextNuclearStrikeVehicleId;
}

int Player::getNextNuclearStrikeTickIndex() const {
    return nextNuclearStrikeTickIndex;
}

double Player::getNextNuclearStrikeX() const {
    return nextNuclearStrikeX;
}

double Player::getNextNuclearStrikeY() const {
    return nextNuclearStrikeY;
}
