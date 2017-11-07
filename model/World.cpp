#include "World.h"

using namespace model;
using namespace std;

World::World()
    : tickIndex(-1), tickCount(-1), width(-1.0), height(-1.0), players(vector<Player>()),
    newVehicles(vector<Vehicle>()), vehicleUpdates(vector<VehicleUpdate>()),
    terrainByCellXY(vector<vector<TerrainType> >()), weatherByCellXY(vector<vector<WeatherType> >()),
    facilities(vector<Facility>()) { }

World::World(int tickIndex, int tickCount, double width, double height, const vector<Player>& players,
    const vector<Vehicle>& newVehicles, const vector<VehicleUpdate>& vehicleUpdates,
    const vector<vector<TerrainType> >& terrainByCellXY, const vector<vector<WeatherType> >& weatherByCellXY,
    const vector<Facility>& facilities)
    : tickIndex(tickIndex), tickCount(tickCount), width(width), height(height), players(players),
    newVehicles(newVehicles), vehicleUpdates(vehicleUpdates), terrainByCellXY(terrainByCellXY),
    weatherByCellXY(weatherByCellXY), facilities(facilities) { }

int World::getTickIndex() const {
    return tickIndex;
}

int World::getTickCount() const {
    return tickCount;
}

double World::getWidth() const {
    return width;
}

double World::getHeight() const {
    return height;
}

const vector<Player>& World::getPlayers() const {
    return players;
}

const vector<Vehicle>& World::getNewVehicles() const {
    return newVehicles;
}

const vector<VehicleUpdate>& World::getVehicleUpdates() const {
    return vehicleUpdates;
}

const vector<vector<TerrainType> >& World::getTerrainByCellXY() const {
    return terrainByCellXY;
}

const vector<vector<WeatherType> >& World::getWeatherByCellXY() const {
    return weatherByCellXY;
}

const vector<Facility>& World::getFacilities() const {
    return facilities;
}

Player World::getMyPlayer() const {
    for (int playerIndex = players.size() - 1; playerIndex >= 0; --playerIndex) {
        Player player = players[playerIndex];
        if (player.isMe()) {
            return player;
        }
    }

    throw;
}

Player World::getOpponentPlayer() const {
    for (int playerIndex = players.size() - 1; playerIndex >= 0; --playerIndex) {
        Player player = players[playerIndex];
        if (!player.isMe()) {
            return player;
        }
    }

    throw;
}
