#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include "Game.h"
#include "Enums.h"

class Game;
using namespace std;

class Player
{
private:
    string playerName;
    int playerID;
    Piece p;
    Game* game;
    int pieceCount;
    /* data */
public:
    Player(int playerID,string playerName,Piece p,Game* game);
    GameStatus move(int x, int y);
    ~Player();
};
#endif