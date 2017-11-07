#pragma once

#ifndef _MY_STRATEGY_H_
#define _MY_STRATEGY_H_

#include "Strategy.h"

class MyStrategy : public Strategy {
public:
    MyStrategy();

    void move(const model::Player& me, const model::World& world, const model::Game& game, model::Move& move) override;
};

#endif
