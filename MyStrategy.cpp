#include "MyStrategy.h"

#define PI 3.14159265358979323846
#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>

using namespace model;
using namespace std;

void MyStrategy::move(const Player& me, const World& world, const Game& game, Move& move) {
    if (world.getTickIndex() == 0) {
        move.setAction(ActionType::CLEAR_AND_SELECT);
        move.setRight(world.getWidth());
        move.setBottom(world.getHeight());
        return;
    }

    if (world.getTickIndex() == 1) {
        move.setAction(ActionType::MOVE);
        move.setX(world.getWidth() / 2.0);
        move.setY(world.getHeight() / 2.0);
    }
}

MyStrategy::MyStrategy() { }
