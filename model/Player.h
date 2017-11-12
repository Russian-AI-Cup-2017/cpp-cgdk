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
        int remainingNuclearStrikeCooldownTicks;
        long long nextNuclearStrikeVehicleId;
        int nextNuclearStrikeTickIndex;
        double nextNuclearStrikeX;
        double nextNuclearStrikeY;
    public:
        Player();
        Player(long long id, bool me, bool strategyCrashed, int score, int remainingActionCooldownTicks,
                int remainingNuclearStrikeCooldownTicks, long long nextNuclearStrikeVehicleId,
                int nextNuclearStrikeTickIndex, double nextNuclearStrikeX, double nextNuclearStrikeY);

        long long getId() const;
        bool isMe() const;
        bool isStrategyCrashed() const;
        int getScore() const;
        int getRemainingActionCooldownTicks() const;
        int getRemainingNuclearStrikeCooldownTicks() const;
        long long getNextNuclearStrikeVehicleId() const;
        int getNextNuclearStrikeTickIndex() const;
        double getNextNuclearStrikeX() const;
        double getNextNuclearStrikeY() const;
    };
}

#endif
