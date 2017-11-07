#include "Runner.h"

#include <memory>

#include "MyStrategy.h"

using namespace model;
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 4) {
        Runner runner(argv[1], argv[2], argv[3]);
        runner.run();
    } else {
        Runner runner("127.0.0.1", "31001", "0000000000000000");
        runner.run();
    }

    return 0;
}

Runner::Runner(const char* host, const char* port, const char* token)
    : remoteProcessClient(host, atoi(port)), token(token) {
}

void Runner::run() {
    remoteProcessClient.writeTokenMessage(token);
    remoteProcessClient.writeProtocolVersionMessage();
    remoteProcessClient.readTeamSizeMessage();
    Game game = remoteProcessClient.readGameContextMessage();

    unique_ptr<Strategy> strategy(new MyStrategy);

    shared_ptr<PlayerContext> playerContext;

    while ((playerContext = remoteProcessClient.readPlayerContextMessage()) != nullptr) {
        Player player = playerContext->getPlayer();

        Move move;
        strategy->move(player, playerContext->getWorld(), game, move);

        remoteProcessClient.writeMoveMessage(move);
    }
}
