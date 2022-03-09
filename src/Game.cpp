#include "Game.h"
#include "Enums.h"

using namespace std;

Game::Game()
{
	this->grid = new Grid();
}

void Game::setStatus(GameStatus Status)
{
    gStatus = Status;
}

GameStatus Game::getStatus()
{
    return gStatus;
}
void Game::setPlayers(Player player)
{
    players.push_back(player);
}


void Game::setGrid(Grid* g)
{
    grid = g;
}

Grid* Game::getGrid()
{
    return grid;
}
