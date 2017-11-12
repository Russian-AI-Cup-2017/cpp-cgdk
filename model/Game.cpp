#include "Game.h"

using namespace model;

Game::Game()
    : randomSeed(-1), tickCount(-1), worldWidth(-1.0), worldHeight(-1.0), fogOfWarEnabled(false), victoryScore(-1),
    facilityCaptureScore(-1), vehicleEliminationScore(-1), actionDetectionInterval(-1), baseActionCount(-1),
    additionalActionCountPerControlCenter(-1), maxUnitGroup(-1), terrainWeatherMapColumnCount(-1),
    terrainWeatherMapRowCount(-1), plainTerrainVisionFactor(-1.0), plainTerrainStealthFactor(-1.0),
    plainTerrainSpeedFactor(-1.0), swampTerrainVisionFactor(-1.0), swampTerrainStealthFactor(-1.0),
    swampTerrainSpeedFactor(-1.0), forestTerrainVisionFactor(-1.0), forestTerrainStealthFactor(-1.0),
    forestTerrainSpeedFactor(-1.0), clearWeatherVisionFactor(-1.0), clearWeatherStealthFactor(-1.0),
    clearWeatherSpeedFactor(-1.0), cloudWeatherVisionFactor(-1.0), cloudWeatherStealthFactor(-1.0),
    cloudWeatherSpeedFactor(-1.0), rainWeatherVisionFactor(-1.0), rainWeatherStealthFactor(-1.0),
    rainWeatherSpeedFactor(-1.0), vehicleRadius(-1.0), tankDurability(-1), tankSpeed(-1.0), tankVisionRange(-1.0),
    tankGroundAttackRange(-1.0), tankAerialAttackRange(-1.0), tankGroundDamage(-1), tankAerialDamage(-1),
    tankGroundDefence(-1), tankAerialDefence(-1), tankAttackCooldownTicks(-1), tankProductionCost(-1),
    ifvDurability(-1), ifvSpeed(-1.0), ifvVisionRange(-1.0), ifvGroundAttackRange(-1.0), ifvAerialAttackRange(-1.0),
    ifvGroundDamage(-1), ifvAerialDamage(-1), ifvGroundDefence(-1), ifvAerialDefence(-1), ifvAttackCooldownTicks(-1),
    ifvProductionCost(-1), arrvDurability(-1), arrvSpeed(-1.0), arrvVisionRange(-1.0), arrvGroundDefence(-1),
    arrvAerialDefence(-1), arrvProductionCost(-1), arrvRepairRange(-1.0), arrvRepairSpeed(-1.0),
    helicopterDurability(-1), helicopterSpeed(-1.0), helicopterVisionRange(-1.0), helicopterGroundAttackRange(-1.0),
    helicopterAerialAttackRange(-1.0), helicopterGroundDamage(-1), helicopterAerialDamage(-1),
    helicopterGroundDefence(-1), helicopterAerialDefence(-1), helicopterAttackCooldownTicks(-1),
    helicopterProductionCost(-1), fighterDurability(-1), fighterSpeed(-1.0), fighterVisionRange(-1.0),
    fighterGroundAttackRange(-1.0), fighterAerialAttackRange(-1.0), fighterGroundDamage(-1), fighterAerialDamage(-1),
    fighterGroundDefence(-1), fighterAerialDefence(-1), fighterAttackCooldownTicks(-1), fighterProductionCost(-1),
    maxFacilityCapturePoints(-1.0), facilityCapturePointsPerVehiclePerTick(-1.0), facilityWidth(-1.0),
    facilityHeight(-1.0), baseTacticalNuclearStrikeCooldown(-1),
    tacticalNuclearStrikeCooldownDecreasePerControlCenter(-1), maxTacticalNuclearStrikeDamage(-1.0),
    tacticalNuclearStrikeRadius(-1.0), tacticalNuclearStrikeDelay(-1) { }

Game::Game(long long randomSeed, int tickCount, double worldWidth, double worldHeight, bool fogOfWarEnabled,
    int victoryScore, int facilityCaptureScore, int vehicleEliminationScore, int actionDetectionInterval,
    int baseActionCount, int additionalActionCountPerControlCenter, int maxUnitGroup, int terrainWeatherMapColumnCount,
    int terrainWeatherMapRowCount, double plainTerrainVisionFactor, double plainTerrainStealthFactor,
    double plainTerrainSpeedFactor, double swampTerrainVisionFactor, double swampTerrainStealthFactor,
    double swampTerrainSpeedFactor, double forestTerrainVisionFactor, double forestTerrainStealthFactor,
    double forestTerrainSpeedFactor, double clearWeatherVisionFactor, double clearWeatherStealthFactor,
    double clearWeatherSpeedFactor, double cloudWeatherVisionFactor, double cloudWeatherStealthFactor,
    double cloudWeatherSpeedFactor, double rainWeatherVisionFactor, double rainWeatherStealthFactor,
    double rainWeatherSpeedFactor, double vehicleRadius, int tankDurability, double tankSpeed, double tankVisionRange,
    double tankGroundAttackRange, double tankAerialAttackRange, int tankGroundDamage, int tankAerialDamage,
    int tankGroundDefence, int tankAerialDefence, int tankAttackCooldownTicks, int tankProductionCost,
    int ifvDurability, double ifvSpeed, double ifvVisionRange, double ifvGroundAttackRange, double ifvAerialAttackRange,
    int ifvGroundDamage, int ifvAerialDamage, int ifvGroundDefence, int ifvAerialDefence, int ifvAttackCooldownTicks,
    int ifvProductionCost, int arrvDurability, double arrvSpeed, double arrvVisionRange, int arrvGroundDefence,
    int arrvAerialDefence, int arrvProductionCost, double arrvRepairRange, double arrvRepairSpeed,
    int helicopterDurability, double helicopterSpeed, double helicopterVisionRange, double helicopterGroundAttackRange,
    double helicopterAerialAttackRange, int helicopterGroundDamage, int helicopterAerialDamage,
    int helicopterGroundDefence, int helicopterAerialDefence, int helicopterAttackCooldownTicks,
    int helicopterProductionCost, int fighterDurability, double fighterSpeed, double fighterVisionRange,
    double fighterGroundAttackRange, double fighterAerialAttackRange, int fighterGroundDamage, int fighterAerialDamage,
    int fighterGroundDefence, int fighterAerialDefence, int fighterAttackCooldownTicks, int fighterProductionCost,
    double maxFacilityCapturePoints, double facilityCapturePointsPerVehiclePerTick, double facilityWidth,
    double facilityHeight, int baseTacticalNuclearStrikeCooldown,
    int tacticalNuclearStrikeCooldownDecreasePerControlCenter, double maxTacticalNuclearStrikeDamage,
    double tacticalNuclearStrikeRadius, int tacticalNuclearStrikeDelay)
    : randomSeed(randomSeed), tickCount(tickCount), worldWidth(worldWidth), worldHeight(worldHeight),
    fogOfWarEnabled(fogOfWarEnabled), victoryScore(victoryScore), facilityCaptureScore(facilityCaptureScore),
    vehicleEliminationScore(vehicleEliminationScore), actionDetectionInterval(actionDetectionInterval),
    baseActionCount(baseActionCount), additionalActionCountPerControlCenter(additionalActionCountPerControlCenter),
    maxUnitGroup(maxUnitGroup), terrainWeatherMapColumnCount(terrainWeatherMapColumnCount),
    terrainWeatherMapRowCount(terrainWeatherMapRowCount), plainTerrainVisionFactor(plainTerrainVisionFactor),
    plainTerrainStealthFactor(plainTerrainStealthFactor), plainTerrainSpeedFactor(plainTerrainSpeedFactor),
    swampTerrainVisionFactor(swampTerrainVisionFactor), swampTerrainStealthFactor(swampTerrainStealthFactor),
    swampTerrainSpeedFactor(swampTerrainSpeedFactor), forestTerrainVisionFactor(forestTerrainVisionFactor),
    forestTerrainStealthFactor(forestTerrainStealthFactor), forestTerrainSpeedFactor(forestTerrainSpeedFactor),
    clearWeatherVisionFactor(clearWeatherVisionFactor), clearWeatherStealthFactor(clearWeatherStealthFactor),
    clearWeatherSpeedFactor(clearWeatherSpeedFactor), cloudWeatherVisionFactor(cloudWeatherVisionFactor),
    cloudWeatherStealthFactor(cloudWeatherStealthFactor), cloudWeatherSpeedFactor(cloudWeatherSpeedFactor),
    rainWeatherVisionFactor(rainWeatherVisionFactor), rainWeatherStealthFactor(rainWeatherStealthFactor),
    rainWeatherSpeedFactor(rainWeatherSpeedFactor), vehicleRadius(vehicleRadius), tankDurability(tankDurability),
    tankSpeed(tankSpeed), tankVisionRange(tankVisionRange), tankGroundAttackRange(tankGroundAttackRange),
    tankAerialAttackRange(tankAerialAttackRange), tankGroundDamage(tankGroundDamage),
    tankAerialDamage(tankAerialDamage), tankGroundDefence(tankGroundDefence), tankAerialDefence(tankAerialDefence),
    tankAttackCooldownTicks(tankAttackCooldownTicks), tankProductionCost(tankProductionCost),
    ifvDurability(ifvDurability), ifvSpeed(ifvSpeed), ifvVisionRange(ifvVisionRange),
    ifvGroundAttackRange(ifvGroundAttackRange), ifvAerialAttackRange(ifvAerialAttackRange),
    ifvGroundDamage(ifvGroundDamage), ifvAerialDamage(ifvAerialDamage), ifvGroundDefence(ifvGroundDefence),
    ifvAerialDefence(ifvAerialDefence), ifvAttackCooldownTicks(ifvAttackCooldownTicks),
    ifvProductionCost(ifvProductionCost), arrvDurability(arrvDurability), arrvSpeed(arrvSpeed),
    arrvVisionRange(arrvVisionRange), arrvGroundDefence(arrvGroundDefence), arrvAerialDefence(arrvAerialDefence),
    arrvProductionCost(arrvProductionCost), arrvRepairRange(arrvRepairRange), arrvRepairSpeed(arrvRepairSpeed),
    helicopterDurability(helicopterDurability), helicopterSpeed(helicopterSpeed),
    helicopterVisionRange(helicopterVisionRange), helicopterGroundAttackRange(helicopterGroundAttackRange),
    helicopterAerialAttackRange(helicopterAerialAttackRange), helicopterGroundDamage(helicopterGroundDamage),
    helicopterAerialDamage(helicopterAerialDamage), helicopterGroundDefence(helicopterGroundDefence),
    helicopterAerialDefence(helicopterAerialDefence), helicopterAttackCooldownTicks(helicopterAttackCooldownTicks),
    helicopterProductionCost(helicopterProductionCost), fighterDurability(fighterDurability),
    fighterSpeed(fighterSpeed), fighterVisionRange(fighterVisionRange),
    fighterGroundAttackRange(fighterGroundAttackRange), fighterAerialAttackRange(fighterAerialAttackRange),
    fighterGroundDamage(fighterGroundDamage), fighterAerialDamage(fighterAerialDamage),
    fighterGroundDefence(fighterGroundDefence), fighterAerialDefence(fighterAerialDefence),
    fighterAttackCooldownTicks(fighterAttackCooldownTicks), fighterProductionCost(fighterProductionCost),
    maxFacilityCapturePoints(maxFacilityCapturePoints),
    facilityCapturePointsPerVehiclePerTick(facilityCapturePointsPerVehiclePerTick), facilityWidth(facilityWidth),
    facilityHeight(facilityHeight), baseTacticalNuclearStrikeCooldown(baseTacticalNuclearStrikeCooldown),
    tacticalNuclearStrikeCooldownDecreasePerControlCenter(tacticalNuclearStrikeCooldownDecreasePerControlCenter),
    maxTacticalNuclearStrikeDamage(maxTacticalNuclearStrikeDamage),
    tacticalNuclearStrikeRadius(tacticalNuclearStrikeRadius), tacticalNuclearStrikeDelay(tacticalNuclearStrikeDelay) { }

long long Game::getRandomSeed() const {
    return randomSeed;
}

int Game::getTickCount() const {
    return tickCount;
}

double Game::getWorldWidth() const {
    return worldWidth;
}

double Game::getWorldHeight() const {
    return worldHeight;
}

bool Game::isFogOfWarEnabled() const {
    return fogOfWarEnabled;
}

int Game::getVictoryScore() const {
    return victoryScore;
}

int Game::getFacilityCaptureScore() const {
    return facilityCaptureScore;
}

int Game::getVehicleEliminationScore() const {
    return vehicleEliminationScore;
}

int Game::getActionDetectionInterval() const {
    return actionDetectionInterval;
}

int Game::getBaseActionCount() const {
    return baseActionCount;
}

int Game::getAdditionalActionCountPerControlCenter() const {
    return additionalActionCountPerControlCenter;
}

int Game::getMaxUnitGroup() const {
    return maxUnitGroup;
}

int Game::getTerrainWeatherMapColumnCount() const {
    return terrainWeatherMapColumnCount;
}

int Game::getTerrainWeatherMapRowCount() const {
    return terrainWeatherMapRowCount;
}

double Game::getPlainTerrainVisionFactor() const {
    return plainTerrainVisionFactor;
}

double Game::getPlainTerrainStealthFactor() const {
    return plainTerrainStealthFactor;
}

double Game::getPlainTerrainSpeedFactor() const {
    return plainTerrainSpeedFactor;
}

double Game::getSwampTerrainVisionFactor() const {
    return swampTerrainVisionFactor;
}

double Game::getSwampTerrainStealthFactor() const {
    return swampTerrainStealthFactor;
}

double Game::getSwampTerrainSpeedFactor() const {
    return swampTerrainSpeedFactor;
}

double Game::getForestTerrainVisionFactor() const {
    return forestTerrainVisionFactor;
}

double Game::getForestTerrainStealthFactor() const {
    return forestTerrainStealthFactor;
}

double Game::getForestTerrainSpeedFactor() const {
    return forestTerrainSpeedFactor;
}

double Game::getClearWeatherVisionFactor() const {
    return clearWeatherVisionFactor;
}

double Game::getClearWeatherStealthFactor() const {
    return clearWeatherStealthFactor;
}

double Game::getClearWeatherSpeedFactor() const {
    return clearWeatherSpeedFactor;
}

double Game::getCloudWeatherVisionFactor() const {
    return cloudWeatherVisionFactor;
}

double Game::getCloudWeatherStealthFactor() const {
    return cloudWeatherStealthFactor;
}

double Game::getCloudWeatherSpeedFactor() const {
    return cloudWeatherSpeedFactor;
}

double Game::getRainWeatherVisionFactor() const {
    return rainWeatherVisionFactor;
}

double Game::getRainWeatherStealthFactor() const {
    return rainWeatherStealthFactor;
}

double Game::getRainWeatherSpeedFactor() const {
    return rainWeatherSpeedFactor;
}

double Game::getVehicleRadius() const {
    return vehicleRadius;
}

int Game::getTankDurability() const {
    return tankDurability;
}

double Game::getTankSpeed() const {
    return tankSpeed;
}

double Game::getTankVisionRange() const {
    return tankVisionRange;
}

double Game::getTankGroundAttackRange() const {
    return tankGroundAttackRange;
}

double Game::getTankAerialAttackRange() const {
    return tankAerialAttackRange;
}

int Game::getTankGroundDamage() const {
    return tankGroundDamage;
}

int Game::getTankAerialDamage() const {
    return tankAerialDamage;
}

int Game::getTankGroundDefence() const {
    return tankGroundDefence;
}

int Game::getTankAerialDefence() const {
    return tankAerialDefence;
}

int Game::getTankAttackCooldownTicks() const {
    return tankAttackCooldownTicks;
}

int Game::getTankProductionCost() const {
    return tankProductionCost;
}

int Game::getIfvDurability() const {
    return ifvDurability;
}

double Game::getIfvSpeed() const {
    return ifvSpeed;
}

double Game::getIfvVisionRange() const {
    return ifvVisionRange;
}

double Game::getIfvGroundAttackRange() const {
    return ifvGroundAttackRange;
}

double Game::getIfvAerialAttackRange() const {
    return ifvAerialAttackRange;
}

int Game::getIfvGroundDamage() const {
    return ifvGroundDamage;
}

int Game::getIfvAerialDamage() const {
    return ifvAerialDamage;
}

int Game::getIfvGroundDefence() const {
    return ifvGroundDefence;
}

int Game::getIfvAerialDefence() const {
    return ifvAerialDefence;
}

int Game::getIfvAttackCooldownTicks() const {
    return ifvAttackCooldownTicks;
}

int Game::getIfvProductionCost() const {
    return ifvProductionCost;
}

int Game::getArrvDurability() const {
    return arrvDurability;
}

double Game::getArrvSpeed() const {
    return arrvSpeed;
}

double Game::getArrvVisionRange() const {
    return arrvVisionRange;
}

int Game::getArrvGroundDefence() const {
    return arrvGroundDefence;
}

int Game::getArrvAerialDefence() const {
    return arrvAerialDefence;
}

int Game::getArrvProductionCost() const {
    return arrvProductionCost;
}

double Game::getArrvRepairRange() const {
    return arrvRepairRange;
}

double Game::getArrvRepairSpeed() const {
    return arrvRepairSpeed;
}

int Game::getHelicopterDurability() const {
    return helicopterDurability;
}

double Game::getHelicopterSpeed() const {
    return helicopterSpeed;
}

double Game::getHelicopterVisionRange() const {
    return helicopterVisionRange;
}

double Game::getHelicopterGroundAttackRange() const {
    return helicopterGroundAttackRange;
}

double Game::getHelicopterAerialAttackRange() const {
    return helicopterAerialAttackRange;
}

int Game::getHelicopterGroundDamage() const {
    return helicopterGroundDamage;
}

int Game::getHelicopterAerialDamage() const {
    return helicopterAerialDamage;
}

int Game::getHelicopterGroundDefence() const {
    return helicopterGroundDefence;
}

int Game::getHelicopterAerialDefence() const {
    return helicopterAerialDefence;
}

int Game::getHelicopterAttackCooldownTicks() const {
    return helicopterAttackCooldownTicks;
}

int Game::getHelicopterProductionCost() const {
    return helicopterProductionCost;
}

int Game::getFighterDurability() const {
    return fighterDurability;
}

double Game::getFighterSpeed() const {
    return fighterSpeed;
}

double Game::getFighterVisionRange() const {
    return fighterVisionRange;
}

double Game::getFighterGroundAttackRange() const {
    return fighterGroundAttackRange;
}

double Game::getFighterAerialAttackRange() const {
    return fighterAerialAttackRange;
}

int Game::getFighterGroundDamage() const {
    return fighterGroundDamage;
}

int Game::getFighterAerialDamage() const {
    return fighterAerialDamage;
}

int Game::getFighterGroundDefence() const {
    return fighterGroundDefence;
}

int Game::getFighterAerialDefence() const {
    return fighterAerialDefence;
}

int Game::getFighterAttackCooldownTicks() const {
    return fighterAttackCooldownTicks;
}

int Game::getFighterProductionCost() const {
    return fighterProductionCost;
}

double Game::getMaxFacilityCapturePoints() const {
    return maxFacilityCapturePoints;
}

double Game::getFacilityCapturePointsPerVehiclePerTick() const {
    return facilityCapturePointsPerVehiclePerTick;
}

double Game::getFacilityWidth() const {
    return facilityWidth;
}

double Game::getFacilityHeight() const {
    return facilityHeight;
}

int Game::getBaseTacticalNuclearStrikeCooldown() const {
    return baseTacticalNuclearStrikeCooldown;
}

int Game::getTacticalNuclearStrikeCooldownDecreasePerControlCenter() const {
    return tacticalNuclearStrikeCooldownDecreasePerControlCenter;
}

double Game::getMaxTacticalNuclearStrikeDamage() const {
    return maxTacticalNuclearStrikeDamage;
}

double Game::getTacticalNuclearStrikeRadius() const {
    return tacticalNuclearStrikeRadius;
}

int Game::getTacticalNuclearStrikeDelay() const {
    return tacticalNuclearStrikeDelay;
}
