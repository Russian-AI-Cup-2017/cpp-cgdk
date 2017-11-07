#pragma once

#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>

#include "Facility.h"
#include "Player.h"
#include "TerrainType.h"
#include "Vehicle.h"
#include "VehicleUpdate.h"
#include "WeatherType.h"

namespace model {
    class World {
    private:
        int tickIndex;
        int tickCount;
        double width;
        double height;
        std::vector<Player> players;
        std::vector<Vehicle> newVehicles;
        std::vector<VehicleUpdate> vehicleUpdates;
        std::vector<std::vector<TerrainType> > terrainByCellXY;
        std::vector<std::vector<WeatherType> > weatherByCellXY;
        std::vector<Facility> facilities;
    public:
        World();
        World(int tickIndex, int tickCount, double width, double height, const std::vector<Player>& players,
                const std::vector<Vehicle>& newVehicles, const std::vector<VehicleUpdate>& vehicleUpdates,
                const std::vector<std::vector<TerrainType> >& terrainByCellXY,
                const std::vector<std::vector<WeatherType> >& weatherByCellXY, const std::vector<Facility>& facilities);

        int getTickIndex() const;
        int getTickCount() const;
        double getWidth() const;
        double getHeight() const;
        const std::vector<Player>& getPlayers() const;
        const std::vector<Vehicle>& getNewVehicles() const;
        const std::vector<VehicleUpdate>& getVehicleUpdates() const;
        const std::vector<std::vector<TerrainType> >& getTerrainByCellXY() const;
        const std::vector<std::vector<WeatherType> >& getWeatherByCellXY() const;
        const std::vector<Facility>& getFacilities() const;

        Player getMyPlayer() const;
        Player getOpponentPlayer() const;
    };
}

#endif
