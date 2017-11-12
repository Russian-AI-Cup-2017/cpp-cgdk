#include "RemoteProcessClient.h"

#include <algorithm>
#include <cstdlib>
#include <memory>

using namespace model;
using namespace std;

const bool LITTLE_ENDIAN_BYTE_ORDER = true;
const int INTEGER_SIZE_BYTES = sizeof(int);
const int LONG_SIZE_BYTES = sizeof(long long);

RemoteProcessClient::RemoteProcessClient(string host, int port)
    : cachedBoolFlag(false), cachedBoolValue(false), previousPlayers(vector<Player> ()),
    previousFacilities(vector<Facility> ()), terrainByCellXY(vector<vector<TerrainType> > ()),
    weatherByCellXY(vector<vector<WeatherType> > ()), previousPlayerById(unordered_map<long long, Player> ()),
    previousFacilityById(unordered_map<long long, Facility>()){
    socket.Initialize();
    socket.DisableNagleAlgoritm();

    if (!socket.Open(reinterpret_cast<const uint8*>(host.c_str()), static_cast<int16>(port))) {
        exit(10001);
    }
}

void RemoteProcessClient::writeTokenMessage(const string& token) {
    writeEnum<MessageType>(AUTHENTICATION_TOKEN);
    writeString(token);
}

void RemoteProcessClient::writeProtocolVersionMessage() {
    writeEnum<MessageType>(PROTOCOL_VERSION);
    writeInt(3);
}

void RemoteProcessClient::readTeamSizeMessage() {
    ensureMessageType(readEnum<MessageType>(), TEAM_SIZE);
    readInt();
}

Game RemoteProcessClient::readGameContextMessage() {
    ensureMessageType(readEnum<MessageType>(), GAME_CONTEXT);
    return readGame();
}

shared_ptr<PlayerContext> RemoteProcessClient::readPlayerContextMessage() {
    MessageType messageType = readEnum<MessageType>();
    if (messageType == GAME_OVER) {
        return nullptr;
    }

    ensureMessageType(messageType, PLAYER_CONTEXT);

    if (!readBoolean()) {
        return nullptr;
    }

    cachedBoolFlag = true;
    cachedBoolValue = true;

    return make_shared<PlayerContext>(readPlayerContext());
}

void RemoteProcessClient::writeMoveMessage(const Move& move) {
    writeEnum<MessageType>(MOVE_MESSAGE);
    writeMove(move);
}

void RemoteProcessClient::close() {
    socket.Close();
}

Facility RemoteProcessClient::readFacility() {
    signed char flag = readByte();

    if (flag == 0) {
        exit(20001);
    }

    if (flag == 127) {
        return previousFacilityById[readLong()];
    }

    long long id = readLong();
    FacilityType type = readEnum<FacilityType>();
    long long ownerPlayerId = readLong();
    double left = readDouble();
    double top = readDouble();
    double capturePoints = readDouble();
    VehicleType vehicleType = readEnum<VehicleType>();
    int productionProgress = readInt();

    Facility facility(id, type, ownerPlayerId, left, top, capturePoints, vehicleType, productionProgress);
    previousFacilityById[facility.getId()] = facility;
    return facility;
}

void RemoteProcessClient::writeFacility(const Facility& facility) {
    writeBoolean(true);

    writeLong(facility.getId());
    writeEnum<FacilityType>(facility.getType());
    writeLong(facility.getOwnerPlayerId());
    writeDouble(facility.getLeft());
    writeDouble(facility.getTop());
    writeDouble(facility.getCapturePoints());
    writeEnum<VehicleType>(facility.getVehicleType());
    writeInt(facility.getProductionProgress());
}

vector<Facility> RemoteProcessClient::readFacilities() {
    int facilityCount = readInt();
    if (facilityCount < 0) {
        return previousFacilities;
    }

    vector<Facility> facilities;
    facilities.reserve(facilityCount);

    for (int facilityIndex = 0; facilityIndex < facilityCount; ++facilityIndex) {
        facilities.push_back(readFacility());
    }

    previousFacilities = facilities;
    return facilities;
}

void RemoteProcessClient::writeFacilities(const vector<Facility>& facilities) {
    int facilityCount = facilities.size();
    writeInt(facilityCount);

    for (int facilityIndex = 0; facilityIndex < facilityCount; ++facilityIndex) {
        writeFacility(facilities[facilityIndex]);
    }
}

Game RemoteProcessClient::readGame() {
    if (!readBoolean()) {
        exit(20003);
    }

    long long randomSeed = readLong();
    int tickCount = readInt();
    double worldWidth = readDouble();
    double worldHeight = readDouble();
    bool fogOfWarEnabled = readBoolean();
    int victoryScore = readInt();
    int facilityCaptureScore = readInt();
    int vehicleEliminationScore = readInt();
    int actionDetectionInterval = readInt();
    int baseActionCount = readInt();
    int additionalActionCountPerControlCenter = readInt();
    int maxUnitGroup = readInt();
    int terrainWeatherMapColumnCount = readInt();
    int terrainWeatherMapRowCount = readInt();
    double plainTerrainVisionFactor = readDouble();
    double plainTerrainStealthFactor = readDouble();
    double plainTerrainSpeedFactor = readDouble();
    double swampTerrainVisionFactor = readDouble();
    double swampTerrainStealthFactor = readDouble();
    double swampTerrainSpeedFactor = readDouble();
    double forestTerrainVisionFactor = readDouble();
    double forestTerrainStealthFactor = readDouble();
    double forestTerrainSpeedFactor = readDouble();
    double clearWeatherVisionFactor = readDouble();
    double clearWeatherStealthFactor = readDouble();
    double clearWeatherSpeedFactor = readDouble();
    double cloudWeatherVisionFactor = readDouble();
    double cloudWeatherStealthFactor = readDouble();
    double cloudWeatherSpeedFactor = readDouble();
    double rainWeatherVisionFactor = readDouble();
    double rainWeatherStealthFactor = readDouble();
    double rainWeatherSpeedFactor = readDouble();
    double vehicleRadius = readDouble();
    int tankDurability = readInt();
    double tankSpeed = readDouble();
    double tankVisionRange = readDouble();
    double tankGroundAttackRange = readDouble();
    double tankAerialAttackRange = readDouble();
    int tankGroundDamage = readInt();
    int tankAerialDamage = readInt();
    int tankGroundDefence = readInt();
    int tankAerialDefence = readInt();
    int tankAttackCooldownTicks = readInt();
    int tankProductionCost = readInt();
    int ifvDurability = readInt();
    double ifvSpeed = readDouble();
    double ifvVisionRange = readDouble();
    double ifvGroundAttackRange = readDouble();
    double ifvAerialAttackRange = readDouble();
    int ifvGroundDamage = readInt();
    int ifvAerialDamage = readInt();
    int ifvGroundDefence = readInt();
    int ifvAerialDefence = readInt();
    int ifvAttackCooldownTicks = readInt();
    int ifvProductionCost = readInt();
    int arrvDurability = readInt();
    double arrvSpeed = readDouble();
    double arrvVisionRange = readDouble();
    int arrvGroundDefence = readInt();
    int arrvAerialDefence = readInt();
    int arrvProductionCost = readInt();
    double arrvRepairRange = readDouble();
    double arrvRepairSpeed = readDouble();
    int helicopterDurability = readInt();
    double helicopterSpeed = readDouble();
    double helicopterVisionRange = readDouble();
    double helicopterGroundAttackRange = readDouble();
    double helicopterAerialAttackRange = readDouble();
    int helicopterGroundDamage = readInt();
    int helicopterAerialDamage = readInt();
    int helicopterGroundDefence = readInt();
    int helicopterAerialDefence = readInt();
    int helicopterAttackCooldownTicks = readInt();
    int helicopterProductionCost = readInt();
    int fighterDurability = readInt();
    double fighterSpeed = readDouble();
    double fighterVisionRange = readDouble();
    double fighterGroundAttackRange = readDouble();
    double fighterAerialAttackRange = readDouble();
    int fighterGroundDamage = readInt();
    int fighterAerialDamage = readInt();
    int fighterGroundDefence = readInt();
    int fighterAerialDefence = readInt();
    int fighterAttackCooldownTicks = readInt();
    int fighterProductionCost = readInt();
    double maxFacilityCapturePoints = readDouble();
    double facilityCapturePointsPerVehiclePerTick = readDouble();
    double facilityWidth = readDouble();
    double facilityHeight = readDouble();
    int baseTacticalNuclearStrikeCooldown = readInt();
    int tacticalNuclearStrikeCooldownDecreasePerControlCenter = readInt();
    double maxTacticalNuclearStrikeDamage = readDouble();
    double tacticalNuclearStrikeRadius = readDouble();
    int tacticalNuclearStrikeDelay = readInt();

    return Game(randomSeed, tickCount, worldWidth, worldHeight, fogOfWarEnabled, victoryScore, facilityCaptureScore,
        vehicleEliminationScore, actionDetectionInterval, baseActionCount, additionalActionCountPerControlCenter,
        maxUnitGroup, terrainWeatherMapColumnCount, terrainWeatherMapRowCount, plainTerrainVisionFactor,
        plainTerrainStealthFactor, plainTerrainSpeedFactor, swampTerrainVisionFactor, swampTerrainStealthFactor,
        swampTerrainSpeedFactor, forestTerrainVisionFactor, forestTerrainStealthFactor, forestTerrainSpeedFactor,
        clearWeatherVisionFactor, clearWeatherStealthFactor, clearWeatherSpeedFactor, cloudWeatherVisionFactor,
        cloudWeatherStealthFactor, cloudWeatherSpeedFactor, rainWeatherVisionFactor, rainWeatherStealthFactor,
        rainWeatherSpeedFactor, vehicleRadius, tankDurability, tankSpeed, tankVisionRange, tankGroundAttackRange,
        tankAerialAttackRange, tankGroundDamage, tankAerialDamage, tankGroundDefence, tankAerialDefence,
        tankAttackCooldownTicks, tankProductionCost, ifvDurability, ifvSpeed, ifvVisionRange, ifvGroundAttackRange,
        ifvAerialAttackRange, ifvGroundDamage, ifvAerialDamage, ifvGroundDefence, ifvAerialDefence,
        ifvAttackCooldownTicks, ifvProductionCost, arrvDurability, arrvSpeed, arrvVisionRange, arrvGroundDefence,
        arrvAerialDefence, arrvProductionCost, arrvRepairRange, arrvRepairSpeed, helicopterDurability, helicopterSpeed,
        helicopterVisionRange, helicopterGroundAttackRange, helicopterAerialAttackRange, helicopterGroundDamage,
        helicopterAerialDamage, helicopterGroundDefence, helicopterAerialDefence, helicopterAttackCooldownTicks,
        helicopterProductionCost, fighterDurability, fighterSpeed, fighterVisionRange, fighterGroundAttackRange,
        fighterAerialAttackRange, fighterGroundDamage, fighterAerialDamage, fighterGroundDefence, fighterAerialDefence,
        fighterAttackCooldownTicks, fighterProductionCost, maxFacilityCapturePoints,
        facilityCapturePointsPerVehiclePerTick, facilityWidth, facilityHeight, baseTacticalNuclearStrikeCooldown,
        tacticalNuclearStrikeCooldownDecreasePerControlCenter, maxTacticalNuclearStrikeDamage,
        tacticalNuclearStrikeRadius, tacticalNuclearStrikeDelay);
}

void RemoteProcessClient::writeGame(const Game& game) {
    writeBoolean(true);

    writeLong(game.getRandomSeed());
    writeInt(game.getTickCount());
    writeDouble(game.getWorldWidth());
    writeDouble(game.getWorldHeight());
    writeBoolean(game.isFogOfWarEnabled());
    writeInt(game.getVictoryScore());
    writeInt(game.getFacilityCaptureScore());
    writeInt(game.getVehicleEliminationScore());
    writeInt(game.getActionDetectionInterval());
    writeInt(game.getBaseActionCount());
    writeInt(game.getAdditionalActionCountPerControlCenter());
    writeInt(game.getMaxUnitGroup());
    writeInt(game.getTerrainWeatherMapColumnCount());
    writeInt(game.getTerrainWeatherMapRowCount());
    writeDouble(game.getPlainTerrainVisionFactor());
    writeDouble(game.getPlainTerrainStealthFactor());
    writeDouble(game.getPlainTerrainSpeedFactor());
    writeDouble(game.getSwampTerrainVisionFactor());
    writeDouble(game.getSwampTerrainStealthFactor());
    writeDouble(game.getSwampTerrainSpeedFactor());
    writeDouble(game.getForestTerrainVisionFactor());
    writeDouble(game.getForestTerrainStealthFactor());
    writeDouble(game.getForestTerrainSpeedFactor());
    writeDouble(game.getClearWeatherVisionFactor());
    writeDouble(game.getClearWeatherStealthFactor());
    writeDouble(game.getClearWeatherSpeedFactor());
    writeDouble(game.getCloudWeatherVisionFactor());
    writeDouble(game.getCloudWeatherStealthFactor());
    writeDouble(game.getCloudWeatherSpeedFactor());
    writeDouble(game.getRainWeatherVisionFactor());
    writeDouble(game.getRainWeatherStealthFactor());
    writeDouble(game.getRainWeatherSpeedFactor());
    writeDouble(game.getVehicleRadius());
    writeInt(game.getTankDurability());
    writeDouble(game.getTankSpeed());
    writeDouble(game.getTankVisionRange());
    writeDouble(game.getTankGroundAttackRange());
    writeDouble(game.getTankAerialAttackRange());
    writeInt(game.getTankGroundDamage());
    writeInt(game.getTankAerialDamage());
    writeInt(game.getTankGroundDefence());
    writeInt(game.getTankAerialDefence());
    writeInt(game.getTankAttackCooldownTicks());
    writeInt(game.getTankProductionCost());
    writeInt(game.getIfvDurability());
    writeDouble(game.getIfvSpeed());
    writeDouble(game.getIfvVisionRange());
    writeDouble(game.getIfvGroundAttackRange());
    writeDouble(game.getIfvAerialAttackRange());
    writeInt(game.getIfvGroundDamage());
    writeInt(game.getIfvAerialDamage());
    writeInt(game.getIfvGroundDefence());
    writeInt(game.getIfvAerialDefence());
    writeInt(game.getIfvAttackCooldownTicks());
    writeInt(game.getIfvProductionCost());
    writeInt(game.getArrvDurability());
    writeDouble(game.getArrvSpeed());
    writeDouble(game.getArrvVisionRange());
    writeInt(game.getArrvGroundDefence());
    writeInt(game.getArrvAerialDefence());
    writeInt(game.getArrvProductionCost());
    writeDouble(game.getArrvRepairRange());
    writeDouble(game.getArrvRepairSpeed());
    writeInt(game.getHelicopterDurability());
    writeDouble(game.getHelicopterSpeed());
    writeDouble(game.getHelicopterVisionRange());
    writeDouble(game.getHelicopterGroundAttackRange());
    writeDouble(game.getHelicopterAerialAttackRange());
    writeInt(game.getHelicopterGroundDamage());
    writeInt(game.getHelicopterAerialDamage());
    writeInt(game.getHelicopterGroundDefence());
    writeInt(game.getHelicopterAerialDefence());
    writeInt(game.getHelicopterAttackCooldownTicks());
    writeInt(game.getHelicopterProductionCost());
    writeInt(game.getFighterDurability());
    writeDouble(game.getFighterSpeed());
    writeDouble(game.getFighterVisionRange());
    writeDouble(game.getFighterGroundAttackRange());
    writeDouble(game.getFighterAerialAttackRange());
    writeInt(game.getFighterGroundDamage());
    writeInt(game.getFighterAerialDamage());
    writeInt(game.getFighterGroundDefence());
    writeInt(game.getFighterAerialDefence());
    writeInt(game.getFighterAttackCooldownTicks());
    writeInt(game.getFighterProductionCost());
    writeDouble(game.getMaxFacilityCapturePoints());
    writeDouble(game.getFacilityCapturePointsPerVehiclePerTick());
    writeDouble(game.getFacilityWidth());
    writeDouble(game.getFacilityHeight());
    writeInt(game.getBaseTacticalNuclearStrikeCooldown());
    writeInt(game.getTacticalNuclearStrikeCooldownDecreasePerControlCenter());
    writeDouble(game.getMaxTacticalNuclearStrikeDamage());
    writeDouble(game.getTacticalNuclearStrikeRadius());
    writeInt(game.getTacticalNuclearStrikeDelay());
}

vector<Game> RemoteProcessClient::readGames() {
    int gameCount = readInt();
    if (gameCount < 0) {
        exit(20004);
    }

    vector<Game> games;
    games.reserve(gameCount);

    for (int gameIndex = 0; gameIndex < gameCount; ++gameIndex) {
        games.push_back(readGame());
    }

    return games;
}

void RemoteProcessClient::writeGames(const vector<Game>& games) {
    int gameCount = games.size();
    writeInt(gameCount);

    for (int gameIndex = 0; gameIndex < gameCount; ++gameIndex) {
        writeGame(games[gameIndex]);
    }
}

void RemoteProcessClient::writeMove(const Move& move) {
    writeBoolean(true);

    writeEnum(move.getAction());
    writeInt(move.getGroup());
    writeDouble(move.getLeft());
    writeDouble(move.getTop());
    writeDouble(move.getRight());
    writeDouble(move.getBottom());
    writeDouble(move.getX());
    writeDouble(move.getY());
    writeDouble(move.getAngle());
    writeDouble(move.getFactor());
    writeDouble(move.getMaxSpeed());
    writeDouble(move.getMaxAngularSpeed());
    writeEnum(move.getVehicleType());
    writeLong(move.getFacilityId());
    writeLong(move.getVehicleId());
}

void RemoteProcessClient::writeMoves(const vector<Move>& moves) {
    int moveCount = moves.size();
    writeInt(moveCount);

    for (int moveIndex = 0; moveIndex < moveCount; ++moveIndex) {
        writeMove(moves[moveIndex]);
    }
}

Player RemoteProcessClient::readPlayer() {
    signed char flag = readByte();

    if (flag == 0) {
        exit(20007);
    }

    if (flag == 127) {
        return previousPlayerById[readLong()];
    }

    long long id = readLong();
    bool me = readBoolean();
    bool strategyCrashed = readBoolean();
    int score = readInt();
    int remainingActionCooldownTicks = readInt();
    int remainingNuclearStrikeCooldownTicks = readInt();
    long long nextNuclearStrikeVehicleId = readLong();
    int nextNuclearStrikeTickIndex = readInt();
    double nextNuclearStrikeX = readDouble();
    double nextNuclearStrikeY = readDouble();

    Player player(id, me, strategyCrashed, score, remainingActionCooldownTicks, remainingNuclearStrikeCooldownTicks,
        nextNuclearStrikeVehicleId, nextNuclearStrikeTickIndex, nextNuclearStrikeX, nextNuclearStrikeY);
    previousPlayerById[player.getId()] = player;
    return player;
}

void RemoteProcessClient::writePlayer(const Player& player) {
    writeBoolean(true);

    writeLong(player.getId());
    writeBoolean(player.isMe());
    writeBoolean(player.isStrategyCrashed());
    writeInt(player.getScore());
    writeInt(player.getRemainingActionCooldownTicks());
    writeInt(player.getRemainingNuclearStrikeCooldownTicks());
    writeLong(player.getNextNuclearStrikeVehicleId());
    writeInt(player.getNextNuclearStrikeTickIndex());
    writeDouble(player.getNextNuclearStrikeX());
    writeDouble(player.getNextNuclearStrikeY());
}

vector<Player> RemoteProcessClient::readPlayers() {
    int playerCount = readInt();
    if (playerCount < 0) {
        return previousPlayers;
    }

    vector<Player> players;
    players.reserve(playerCount);

    for (int playerIndex = 0; playerIndex < playerCount; ++playerIndex) {
        players.push_back(readPlayer());
    }

    previousPlayers = players;
    return players;
}

void RemoteProcessClient::writePlayers(const vector<Player>& players) {
    int playerCount = players.size();
    writeInt(playerCount);

    for (int playerIndex = 0; playerIndex < playerCount; ++playerIndex) {
        writePlayer(players[playerIndex]);
    }
}

PlayerContext RemoteProcessClient::readPlayerContext() {
    if (!readBoolean()) {
        exit(20009);
    }

    Player player = readPlayer();
    World world = readWorld();

    return PlayerContext(player, world);
}

void RemoteProcessClient::writePlayerContext(const PlayerContext& playerContext) {
    writeBoolean(true);

    writePlayer(playerContext.getPlayer());
    writeWorld(playerContext.getWorld());
}

vector<PlayerContext> RemoteProcessClient::readPlayerContexts() {
    int playerContextCount = readInt();
    if (playerContextCount < 0) {
        exit(20010);
    }

    vector<PlayerContext> playerContexts;
    playerContexts.reserve(playerContextCount);

    for (int playerContextIndex = 0; playerContextIndex < playerContextCount; ++playerContextIndex) {
        playerContexts.push_back(readPlayerContext());
    }

    return playerContexts;
}

void RemoteProcessClient::writePlayerContexts(const vector<PlayerContext>& playerContexts) {
    int playerContextCount = playerContexts.size();
    writeInt(playerContextCount);

    for (int playerContextIndex = 0; playerContextIndex < playerContextCount; ++playerContextIndex) {
        writePlayerContext(playerContexts[playerContextIndex]);
    }
}

Vehicle RemoteProcessClient::readVehicle() {
    if (!readBoolean()) {
        exit(20011);
    }

    long long id = readLong();
    double x = readDouble();
    double y = readDouble();
    double radius = readDouble();
    long long playerId = readLong();
    int durability = readInt();
    int maxDurability = readInt();
    double maxSpeed = readDouble();
    double visionRange = readDouble();
    double squaredVisionRange = readDouble();
    double groundAttackRange = readDouble();
    double squaredGroundAttackRange = readDouble();
    double aerialAttackRange = readDouble();
    double squaredAerialAttackRange = readDouble();
    int groundDamage = readInt();
    int aerialDamage = readInt();
    int groundDefence = readInt();
    int aerialDefence = readInt();
    int attackCooldownTicks = readInt();
    int remainingAttackCooldownTicks = readInt();
    VehicleType type = readEnum<VehicleType>();
    bool aerial = readBoolean();
    bool selected = readBoolean();
    vector<int> groups = readIntArray();

    return Vehicle(id, x, y, radius, playerId, durability, maxDurability, maxSpeed, visionRange, squaredVisionRange,
        groundAttackRange, squaredGroundAttackRange, aerialAttackRange, squaredAerialAttackRange, groundDamage,
        aerialDamage, groundDefence, aerialDefence, attackCooldownTicks, remainingAttackCooldownTicks, type, aerial,
        selected, groups);
}

void RemoteProcessClient::writeVehicle(const Vehicle& vehicle) {
    writeBoolean(true);

    writeLong(vehicle.getId());
    writeDouble(vehicle.getX());
    writeDouble(vehicle.getY());
    writeDouble(vehicle.getRadius());
    writeLong(vehicle.getPlayerId());
    writeInt(vehicle.getDurability());
    writeInt(vehicle.getMaxDurability());
    writeDouble(vehicle.getMaxSpeed());
    writeDouble(vehicle.getVisionRange());
    writeDouble(vehicle.getSquaredVisionRange());
    writeDouble(vehicle.getGroundAttackRange());
    writeDouble(vehicle.getSquaredGroundAttackRange());
    writeDouble(vehicle.getAerialAttackRange());
    writeDouble(vehicle.getSquaredAerialAttackRange());
    writeInt(vehicle.getGroundDamage());
    writeInt(vehicle.getAerialDamage());
    writeInt(vehicle.getGroundDefence());
    writeInt(vehicle.getAerialDefence());
    writeInt(vehicle.getAttackCooldownTicks());
    writeInt(vehicle.getRemainingAttackCooldownTicks());
    writeEnum<VehicleType>(vehicle.getType());
    writeBoolean(vehicle.isAerial());
    writeBoolean(vehicle.isSelected());
    writeIntArray(vehicle.getGroups());
}

vector<Vehicle> RemoteProcessClient::readVehicles() {
    int vehicleCount = readInt();
    if (vehicleCount < 0) {
        exit(20012);
    }

    vector<Vehicle> vehicles;
    vehicles.reserve(vehicleCount);

    for (int vehicleIndex = 0; vehicleIndex < vehicleCount; ++vehicleIndex) {
        vehicles.push_back(readVehicle());
    }

    return vehicles;
}

void RemoteProcessClient::writeVehicles(const vector<Vehicle>& vehicles) {
    int vehicleCount = vehicles.size();
    writeInt(vehicleCount);

    for (int vehicleIndex = 0; vehicleIndex < vehicleCount; ++vehicleIndex) {
        writeVehicle(vehicles[vehicleIndex]);
    }
}

VehicleUpdate RemoteProcessClient::readVehicleUpdate() {
    if (!readBoolean()) {
        exit(20013);
    }

    long long id = readLong();
    double x = readDouble();
    double y = readDouble();
    int durability = readInt();
    int remainingAttackCooldownTicks = readInt();
    bool selected = readBoolean();
    vector<int> groups = readIntArray();

    return VehicleUpdate(id, x, y, durability, remainingAttackCooldownTicks, selected, groups);
}

void RemoteProcessClient::writeVehicleUpdate(const VehicleUpdate& vehicleUpdate) {
    writeBoolean(true);

    writeLong(vehicleUpdate.getId());
    writeDouble(vehicleUpdate.getX());
    writeDouble(vehicleUpdate.getY());
    writeInt(vehicleUpdate.getDurability());
    writeInt(vehicleUpdate.getRemainingAttackCooldownTicks());
    writeBoolean(vehicleUpdate.isSelected());
    writeIntArray(vehicleUpdate.getGroups());
}

vector<VehicleUpdate> RemoteProcessClient::readVehicleUpdates() {
    int vehicleUpdateCount = readInt();
    if (vehicleUpdateCount < 0) {
        exit(20014);
    }

    vector<VehicleUpdate> vehicleUpdates;
    vehicleUpdates.reserve(vehicleUpdateCount);

    for (int vehicleUpdateIndex = 0; vehicleUpdateIndex < vehicleUpdateCount; ++vehicleUpdateIndex) {
        vehicleUpdates.push_back(readVehicleUpdate());
    }

    return vehicleUpdates;
}

void RemoteProcessClient::writeVehicleUpdates(const vector<VehicleUpdate>& vehicleUpdates) {
    int vehicleUpdateCount = vehicleUpdates.size();
    writeInt(vehicleUpdateCount);

    for (int vehicleUpdateIndex = 0; vehicleUpdateIndex < vehicleUpdateCount; ++vehicleUpdateIndex) {
        writeVehicleUpdate(vehicleUpdates[vehicleUpdateIndex]);
    }
}

World RemoteProcessClient::readWorld() {
    if (!readBoolean()) {
        exit(20015);
    }

    int tickIndex = readInt();
    int tickCount = readInt();
    double width = readDouble();
    double height = readDouble();
    vector<Player> players = readPlayers();
    vector<Vehicle> newVehicles = readVehicles();
    vector<VehicleUpdate> vehicleUpdates = readVehicleUpdates();

    if (terrainByCellXY.empty()) {
        terrainByCellXY = readEnumArray2D<TerrainType>();
    }

    if (weatherByCellXY.empty()) {
        weatherByCellXY = readEnumArray2D<WeatherType>();
    }

    vector<Facility> facilities = readFacilities();

    return World(tickIndex, tickCount, width, height, players, newVehicles, vehicleUpdates, terrainByCellXY,
        weatherByCellXY, facilities);
}

void RemoteProcessClient::writeWorld(const World& world) {
    writeBoolean(true);

    writeInt(world.getTickIndex());
    writeInt(world.getTickCount());
    writeDouble(world.getWidth());
    writeDouble(world.getHeight());
    writePlayers(world.getPlayers());
    writeVehicles(world.getNewVehicles());
    writeVehicleUpdates(world.getVehicleUpdates());
    writeEnumArray2D<TerrainType>(world.getTerrainByCellXY());
    writeEnumArray2D<WeatherType>(world.getWeatherByCellXY());
    writeFacilities(world.getFacilities());
}

vector<World> RemoteProcessClient::readWorlds() {
    int worldCount = readInt();
    if (worldCount < 0) {
        exit(20016);
    }

    vector<World> worlds;
    worlds.reserve(worldCount);

    for (int worldIndex = 0; worldIndex < worldCount; ++worldIndex) {
        worlds.push_back(readWorld());
    }

    return worlds;
}

void RemoteProcessClient::writeWorlds(const vector<World>& worlds) {
    int worldCount = worlds.size();
    writeInt(worldCount);

    for (int worldIndex = 0; worldIndex < worldCount; ++worldIndex) {
        writeWorld(worlds[worldIndex]);
    }
}

void RemoteProcessClient::ensureMessageType(MessageType actualType, MessageType expectedType) {
    if (actualType != expectedType) {
        exit(10011);
    }
}

vector<signed char> RemoteProcessClient::readByteArray() {
    int count = readInt();
    if (count <= 0) {
        return vector<signed char>();
    }

    return readBytes(count);
}

void RemoteProcessClient::writeByteArray(const vector<signed char>& value) {
    writeInt(value.size());
    writeBytes(value);
}

template <typename E> E RemoteProcessClient::readEnum() {
    return static_cast<E>(this->readByte());
}

template <typename E> vector<E> RemoteProcessClient::readEnumArray() {
    int length = readInt();
    if (length < 0) {
        exit(10015);
    }

    vector<E> value;
    value.reserve(length);

    for (int i = 0; i < length; ++i) {
        value.push_back(readEnum<E>());
    }

    return value;
}

template <typename E> vector<vector<E> > RemoteProcessClient::readEnumArray2D() {
    int length = readInt();
    if (length < 0) {
        exit(10016);
    }

    vector<vector<E> > value(length);

    for (int i = 0; i < length; ++i) {
        int length2 = readInt();
        if (length2 < 0) {
            exit(10017);
        }

        vector<E>& value2 = value[i];
        value2.reserve(length2);

        for (int j = 0; j < length2; ++j) {
            value2.push_back(readEnum<E>());
        }
    }

    return value;
}

template <typename E> void RemoteProcessClient::writeEnum(E value) {
    vector<signed char> bytes;
    bytes.push_back(static_cast<signed char>(value));
    this->writeBytes(bytes);
}

template <typename E> void RemoteProcessClient::writeEnumArray(const vector<E>& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeEnum<E>(value[i]);
    }
}

template <typename E> void RemoteProcessClient::writeEnumArray2D(const vector<vector<E> >& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeEnumArray<E>(value[i]);
    }
}

string RemoteProcessClient::readString() {
    int length = this->readInt();
    if (length == -1) {
        exit(10014);
    }

    if (length == 0) {
        return "";
    }

    vector<signed char> bytes = this->readBytes(length);
    return string(reinterpret_cast<char*>(&bytes[0]), length);
}

void RemoteProcessClient::writeString(const string& value) {
    size_t length = value.size();
    if (length == 0) {
        this->writeInt(0);
        return;
    }

    vector<signed char> bytes(length);

    memcpy(&bytes[0], value.c_str(), length);

    this->writeInt(static_cast<int>(bytes.size()));
    this->writeBytes(bytes);
}

bool RemoteProcessClient::readBoolean() {
    if (cachedBoolFlag) {
        cachedBoolFlag = false;
        return cachedBoolValue;
    }
    return this->readByte() != 0;
}

void RemoteProcessClient::writeBoolean(bool value) {
    this->writeByte(static_cast<signed char>(value ? 1 : 0));
}

int RemoteProcessClient::readInt() {
    vector<signed char> bytes = this->readBytes(INTEGER_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    int value;
    memcpy(&value, &bytes[0], INTEGER_SIZE_BYTES);
    return value;
}

vector<int> RemoteProcessClient::readIntArray() {
    int length = readInt();
    if (length < 0) {
        exit(10018);
    }

    vector<int> value;
    value.reserve(length);

    for (int i = 0; i < length; ++i) {
        value.push_back(readInt());
    }

    return value;
}

vector<vector<int> > RemoteProcessClient::readIntArray2D() {
    int length = readInt();
    if (length < 0) {
        exit(10019);
    }

    vector<vector<int> > value(length);

    for (int i = 0; i < length; ++i) {
        int length2 = readInt();
        if (length2 < 0) {
            exit(10020);
        }

        vector<int>& value2 = value[i];
        value2.reserve(length2);

        for (int j = 0; j < length2; ++j) {
            value2.push_back(readInt());
        }
    }

    return value;
}

void RemoteProcessClient::writeInt(int value) {
    vector<signed char> bytes(INTEGER_SIZE_BYTES);

    memcpy(&bytes[0], &value, INTEGER_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    this->writeBytes(bytes);
}

void RemoteProcessClient::writeIntArray(const vector<int>& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeInt(value[i]);
    }
}

void RemoteProcessClient::writeIntArray2D(const vector<vector<int> >& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeIntArray(value[i]);
    }
}

long long RemoteProcessClient::readLong() {
    vector<signed char> bytes = this->readBytes(LONG_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    long long value;
    memcpy(&value, &bytes[0], LONG_SIZE_BYTES);
    return value;
}

void RemoteProcessClient::writeLong(long long value) {
    vector<signed char> bytes(LONG_SIZE_BYTES);

    memcpy(&bytes[0], &value, LONG_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    this->writeBytes(bytes);
}

double RemoteProcessClient::readDouble() {
    long long value = this->readLong();
    return *reinterpret_cast<double*>(&value);
}

void RemoteProcessClient::writeDouble(double value) {
    this->writeLong(*reinterpret_cast<long long*>(&value));
}

signed char RemoteProcessClient::readByte() {
    if (socket.Receive(1) != 1) {
        exit(10021);
    }

    signed char value;
    memcpy(&value, socket.GetData(), 1);
    return value;
}

vector<signed char> RemoteProcessClient::readBytes(unsigned int byteCount) {
    vector<signed char> bytes(byteCount);
    unsigned int offset = 0;
    int receivedByteCount;

    while (offset < byteCount && (receivedByteCount = socket.Receive(byteCount - offset)) > 0) {
        memcpy(&bytes[offset], socket.GetData(), receivedByteCount);
        offset += receivedByteCount;
    }

    if (offset != byteCount) {
        exit(10012);
    }

    return bytes;
}

void RemoteProcessClient::writeByte(signed char value) {
    if (socket.Send(reinterpret_cast<const uint8*>(&value), 1) != 1) {
        exit(10022);
    }
}

void RemoteProcessClient::writeBytes(const vector<signed char>& bytes) {
    vector<signed char>::size_type byteCount = bytes.size();
    unsigned int offset = 0;
    int sentByteCount;

    while (offset < byteCount && (sentByteCount = socket.Send(reinterpret_cast<const uint8*>(&bytes[offset]), byteCount - offset)) > 0) {
        offset += sentByteCount;
    }

    if (offset != byteCount) {
        exit(10013);
    }
}

bool RemoteProcessClient::isLittleEndianMachine() {
    union {
        uint16 value;
        unsigned char bytes[2];
    } test = {0x0201};

    return test.bytes[0] == 1;
}

RemoteProcessClient::~RemoteProcessClient() {
    this->close();
}
