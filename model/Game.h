#pragma once

#ifndef _GAME_H_
#define _GAME_H_

namespace model {
    class Game {
    private:
        long long randomSeed;
        int tickCount;
        double worldWidth;
        double worldHeight;
        bool fogOfWarEnabled;
        int victoryScore;
        int facilityCaptureScore;
        int vehicleEliminationScore;
        int actionDetectionInterval;
        int baseActionCount;
        int additionalActionCountPerControlCenter;
        int maxUnitGroup;
        int terrainWeatherMapColumnCount;
        int terrainWeatherMapRowCount;
        double plainTerrainVisionFactor;
        double plainTerrainStealthFactor;
        double plainTerrainSpeedFactor;
        double swampTerrainVisionFactor;
        double swampTerrainStealthFactor;
        double swampTerrainSpeedFactor;
        double forestTerrainVisionFactor;
        double forestTerrainStealthFactor;
        double forestTerrainSpeedFactor;
        double clearWeatherVisionFactor;
        double clearWeatherStealthFactor;
        double clearWeatherSpeedFactor;
        double cloudWeatherVisionFactor;
        double cloudWeatherStealthFactor;
        double cloudWeatherSpeedFactor;
        double rainWeatherVisionFactor;
        double rainWeatherStealthFactor;
        double rainWeatherSpeedFactor;
        double vehicleRadius;
        int tankDurability;
        double tankSpeed;
        double tankVisionRange;
        double tankGroundAttackRange;
        double tankAerialAttackRange;
        int tankGroundDamage;
        int tankAerialDamage;
        int tankGroundDefence;
        int tankAerialDefence;
        int tankAttackCooldownTicks;
        int tankProductionCost;
        int ifvDurability;
        double ifvSpeed;
        double ifvVisionRange;
        double ifvGroundAttackRange;
        double ifvAerialAttackRange;
        int ifvGroundDamage;
        int ifvAerialDamage;
        int ifvGroundDefence;
        int ifvAerialDefence;
        int ifvAttackCooldownTicks;
        int ifvProductionCost;
        int arrvDurability;
        double arrvSpeed;
        double arrvVisionRange;
        int arrvGroundDefence;
        int arrvAerialDefence;
        int arrvProductionCost;
        double arrvRepairRange;
        double arrvRepairSpeed;
        int helicopterDurability;
        double helicopterSpeed;
        double helicopterVisionRange;
        double helicopterGroundAttackRange;
        double helicopterAerialAttackRange;
        int helicopterGroundDamage;
        int helicopterAerialDamage;
        int helicopterGroundDefence;
        int helicopterAerialDefence;
        int helicopterAttackCooldownTicks;
        int helicopterProductionCost;
        int fighterDurability;
        double fighterSpeed;
        double fighterVisionRange;
        double fighterGroundAttackRange;
        double fighterAerialAttackRange;
        int fighterGroundDamage;
        int fighterAerialDamage;
        int fighterGroundDefence;
        int fighterAerialDefence;
        int fighterAttackCooldownTicks;
        int fighterProductionCost;
        double maxFacilityCapturePoints;
        double facilityCapturePointsPerVehiclePerTick;
        double facilityWidth;
        double facilityHeight;
        int baseTacticalNuclearStrikeCooldown;
        int tacticalNuclearStrikeCooldownDecreasePerControlCenter;
        double maxTacticalNuclearStrikeDamage;
        double tacticalNuclearStrikeRadius;
        int tacticalNuclearStrikeDelay;
    public:
        Game();
        Game(long long randomSeed, int tickCount, double worldWidth, double worldHeight, bool fogOfWarEnabled,
                int victoryScore, int facilityCaptureScore, int vehicleEliminationScore, int actionDetectionInterval,
                int baseActionCount, int additionalActionCountPerControlCenter, int maxUnitGroup,
                int terrainWeatherMapColumnCount, int terrainWeatherMapRowCount, double plainTerrainVisionFactor,
                double plainTerrainStealthFactor, double plainTerrainSpeedFactor, double swampTerrainVisionFactor,
                double swampTerrainStealthFactor, double swampTerrainSpeedFactor, double forestTerrainVisionFactor,
                double forestTerrainStealthFactor, double forestTerrainSpeedFactor, double clearWeatherVisionFactor,
                double clearWeatherStealthFactor, double clearWeatherSpeedFactor, double cloudWeatherVisionFactor,
                double cloudWeatherStealthFactor, double cloudWeatherSpeedFactor, double rainWeatherVisionFactor,
                double rainWeatherStealthFactor, double rainWeatherSpeedFactor, double vehicleRadius,
                int tankDurability, double tankSpeed, double tankVisionRange, double tankGroundAttackRange,
                double tankAerialAttackRange, int tankGroundDamage, int tankAerialDamage, int tankGroundDefence,
                int tankAerialDefence, int tankAttackCooldownTicks, int tankProductionCost, int ifvDurability,
                double ifvSpeed, double ifvVisionRange, double ifvGroundAttackRange, double ifvAerialAttackRange,
                int ifvGroundDamage, int ifvAerialDamage, int ifvGroundDefence, int ifvAerialDefence,
                int ifvAttackCooldownTicks, int ifvProductionCost, int arrvDurability, double arrvSpeed,
                double arrvVisionRange, int arrvGroundDefence, int arrvAerialDefence, int arrvProductionCost,
                double arrvRepairRange, double arrvRepairSpeed, int helicopterDurability, double helicopterSpeed,
                double helicopterVisionRange, double helicopterGroundAttackRange, double helicopterAerialAttackRange,
                int helicopterGroundDamage, int helicopterAerialDamage, int helicopterGroundDefence,
                int helicopterAerialDefence, int helicopterAttackCooldownTicks, int helicopterProductionCost,
                int fighterDurability, double fighterSpeed, double fighterVisionRange, double fighterGroundAttackRange,
                double fighterAerialAttackRange, int fighterGroundDamage, int fighterAerialDamage,
                int fighterGroundDefence, int fighterAerialDefence, int fighterAttackCooldownTicks,
                int fighterProductionCost, double maxFacilityCapturePoints,
                double facilityCapturePointsPerVehiclePerTick, double facilityWidth, double facilityHeight,
                int baseTacticalNuclearStrikeCooldown, int tacticalNuclearStrikeCooldownDecreasePerControlCenter,
                double maxTacticalNuclearStrikeDamage, double tacticalNuclearStrikeRadius,
                int tacticalNuclearStrikeDelay);

        long long getRandomSeed() const;
        int getTickCount() const;
        double getWorldWidth() const;
        double getWorldHeight() const;
        bool isFogOfWarEnabled() const;
        int getVictoryScore() const;
        int getFacilityCaptureScore() const;
        int getVehicleEliminationScore() const;
        int getActionDetectionInterval() const;
        int getBaseActionCount() const;
        int getAdditionalActionCountPerControlCenter() const;
        int getMaxUnitGroup() const;
        int getTerrainWeatherMapColumnCount() const;
        int getTerrainWeatherMapRowCount() const;
        double getPlainTerrainVisionFactor() const;
        double getPlainTerrainStealthFactor() const;
        double getPlainTerrainSpeedFactor() const;
        double getSwampTerrainVisionFactor() const;
        double getSwampTerrainStealthFactor() const;
        double getSwampTerrainSpeedFactor() const;
        double getForestTerrainVisionFactor() const;
        double getForestTerrainStealthFactor() const;
        double getForestTerrainSpeedFactor() const;
        double getClearWeatherVisionFactor() const;
        double getClearWeatherStealthFactor() const;
        double getClearWeatherSpeedFactor() const;
        double getCloudWeatherVisionFactor() const;
        double getCloudWeatherStealthFactor() const;
        double getCloudWeatherSpeedFactor() const;
        double getRainWeatherVisionFactor() const;
        double getRainWeatherStealthFactor() const;
        double getRainWeatherSpeedFactor() const;
        double getVehicleRadius() const;
        int getTankDurability() const;
        double getTankSpeed() const;
        double getTankVisionRange() const;
        double getTankGroundAttackRange() const;
        double getTankAerialAttackRange() const;
        int getTankGroundDamage() const;
        int getTankAerialDamage() const;
        int getTankGroundDefence() const;
        int getTankAerialDefence() const;
        int getTankAttackCooldownTicks() const;
        int getTankProductionCost() const;
        int getIfvDurability() const;
        double getIfvSpeed() const;
        double getIfvVisionRange() const;
        double getIfvGroundAttackRange() const;
        double getIfvAerialAttackRange() const;
        int getIfvGroundDamage() const;
        int getIfvAerialDamage() const;
        int getIfvGroundDefence() const;
        int getIfvAerialDefence() const;
        int getIfvAttackCooldownTicks() const;
        int getIfvProductionCost() const;
        int getArrvDurability() const;
        double getArrvSpeed() const;
        double getArrvVisionRange() const;
        int getArrvGroundDefence() const;
        int getArrvAerialDefence() const;
        int getArrvProductionCost() const;
        double getArrvRepairRange() const;
        double getArrvRepairSpeed() const;
        int getHelicopterDurability() const;
        double getHelicopterSpeed() const;
        double getHelicopterVisionRange() const;
        double getHelicopterGroundAttackRange() const;
        double getHelicopterAerialAttackRange() const;
        int getHelicopterGroundDamage() const;
        int getHelicopterAerialDamage() const;
        int getHelicopterGroundDefence() const;
        int getHelicopterAerialDefence() const;
        int getHelicopterAttackCooldownTicks() const;
        int getHelicopterProductionCost() const;
        int getFighterDurability() const;
        double getFighterSpeed() const;
        double getFighterVisionRange() const;
        double getFighterGroundAttackRange() const;
        double getFighterAerialAttackRange() const;
        int getFighterGroundDamage() const;
        int getFighterAerialDamage() const;
        int getFighterGroundDefence() const;
        int getFighterAerialDefence() const;
        int getFighterAttackCooldownTicks() const;
        int getFighterProductionCost() const;
        double getMaxFacilityCapturePoints() const;
        double getFacilityCapturePointsPerVehiclePerTick() const;
        double getFacilityWidth() const;
        double getFacilityHeight() const;
        int getBaseTacticalNuclearStrikeCooldown() const;
        int getTacticalNuclearStrikeCooldownDecreasePerControlCenter() const;
        double getMaxTacticalNuclearStrikeDamage() const;
        double getTacticalNuclearStrikeRadius() const;
        int getTacticalNuclearStrikeDelay() const;
    };
}

#endif
