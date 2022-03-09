#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Grid.h"
#include "Player.h"
#include "Enums.h"

class Player;
class Grid;

using namespace std;

class Game
{
private:
    static long long int gameID;
    vector<Player> players;
    Grid* grid;
    GameStatus gStatus;

public:
    Game();
    void setStatus(GameStatus status);
    GameStatus getStatus();
    void setPlayers(Player player);
    void setGrid(Grid* g);
    Grid* getGrid();
};

#endif