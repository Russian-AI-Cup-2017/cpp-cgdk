#pragma once

#ifndef _REMOTE_PROCESS_CLIENT_H_
#define _REMOTE_PROCESS_CLIENT_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "csimplesocket/ActiveSocket.h"
#include "model/Game.h"
#include "model/Move.h"
#include "model/PlayerContext.h"
#include "model/World.h"

enum MessageType {
    UNKNOWN_MESSAGE,
    GAME_OVER,
    AUTHENTICATION_TOKEN,
    TEAM_SIZE,
    PROTOCOL_VERSION,
    GAME_CONTEXT,
    PLAYER_CONTEXT,
    MOVE_MESSAGE
};

class RemoteProcessClient {
    CActiveSocket socket;
    bool cachedBoolFlag;
    bool cachedBoolValue;

    std::vector<model::Player> previousPlayers;
    std::vector<model::Facility> previousFacilities;
    std::vector<std::vector<model::TerrainType> > terrainByCellXY;
    std::vector<std::vector<model::WeatherType> > weatherByCellXY;

    std::unordered_map<long long, model::Player> previousPlayerById;
    std::unordered_map<long long, model::Facility> previousFacilityById;

    model::Facility readFacility();
    void writeFacility(const model::Facility& facility);
    std::vector<model::Facility> readFacilities();
    void writeFacilities(const std::vector<model::Facility>& facilities);
    model::Game readGame();
    void writeGame(const model::Game& game);
    std::vector<model::Game> readGames();
    void writeGames(const std::vector<model::Game>& games);
    void writeMove(const model::Move& move);
    void writeMoves(const std::vector<model::Move>& moves);
    model::Player readPlayer();
    void writePlayer(const model::Player& player);
    std::vector<model::Player> readPlayers();
    void writePlayers(const std::vector<model::Player>& players);
    model::PlayerContext readPlayerContext();
    void writePlayerContext(const model::PlayerContext& playerContext);
    std::vector<model::PlayerContext> readPlayerContexts();
    void writePlayerContexts(const std::vector<model::PlayerContext>& playerContexts);
    model::Vehicle readVehicle();
    void writeVehicle(const model::Vehicle& vehicle);
    std::vector<model::Vehicle> readVehicles();
    void writeVehicles(const std::vector<model::Vehicle>& vehicles);
    model::VehicleUpdate readVehicleUpdate();
    void writeVehicleUpdate(const model::VehicleUpdate& vehicleUpdate);
    std::vector<model::VehicleUpdate> readVehicleUpdates();
    void writeVehicleUpdates(const std::vector<model::VehicleUpdate>& vehicleUpdates);
    model::World readWorld();
    void writeWorld(const model::World& world);
    std::vector<model::World> readWorlds();
    void writeWorlds(const std::vector<model::World>& worlds);

    static void ensureMessageType(MessageType actualType, MessageType expectedType);

    std::vector<signed char> readByteArray();
    void writeByteArray(const std::vector<signed char>& value);

    template <typename E> E readEnum();
    template <typename E> std::vector<E> readEnumArray();
    template <typename E> std::vector<std::vector<E> > readEnumArray2D();
    template <typename E> void writeEnum(E value);
    template <typename E> void writeEnumArray(const std::vector<E>& value);
    template <typename E> void writeEnumArray2D(const std::vector<std::vector<E> >& value);

    std::string readString();
    void writeString(const std::string& value);

    bool readBoolean();
    void writeBoolean(bool value);

    int readInt();
    std::vector<int> readIntArray();
    std::vector<std::vector<int> > readIntArray2D();
    void writeInt(int value);
    void writeIntArray(const std::vector<int>& value);
    void writeIntArray2D(const std::vector<std::vector<int> >& value);

    long long readLong();
    void writeLong(long long value);

    double readDouble();
    void writeDouble(double value);

    signed char readByte();
    std::vector<signed char> readBytes(unsigned int byteCount);
    void writeByte(signed char value);
    void writeBytes(const std::vector<signed char>& bytes);

    static bool isLittleEndianMachine();
public:
    RemoteProcessClient(std::string host, int port);

    void writeTokenMessage(const std::string& token);
    void writeProtocolVersionMessage();
    void readTeamSizeMessage();
    model::Game readGameContextMessage();
    std::shared_ptr<model::PlayerContext> readPlayerContextMessage();
    void writeMoveMessage(const model::Move& move);

    void close();

    ~RemoteProcessClient();
};

#endif
