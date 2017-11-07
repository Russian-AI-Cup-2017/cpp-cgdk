#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

namespace model {
    class Player {
    private:
        long long id;
        bool me;
        bool strategyCrashed;
        int score;
        int remainingActionCooldownTicks;
    public:
        Player();
        Player(long long id, bool me, bool strategyCrashed, int score, int remainingActionCooldownTicks);

        long long getId() const;
        bool isMe() const;
        bool isStrategyCrashed() const;
        int getScore() const;
        int getRemainingActionCooldownTicks() const;
    };
}

#endif
