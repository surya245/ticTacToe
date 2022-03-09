#include<iostream>
#include "Player.h"
#include "Game.h"

using namespace std;

Player::Player(int playerID,string playerName,Piece p,Game* game)
{
    this->playerID   = playerID;
    this->playerName = playerName;
    this->p          = p;
    this->game       = game;

    if(p == 0)
        pieceCount = 5;
    else
        pieceCount = 4;
}
GameStatus Player::move(int x,int y)
{
	if(x < 0 || y < 0 || x>=3 || y >=3)
		return INVALID_MOVE;
    Grid* grid = game->getGrid();
	Cell* cell = grid->getCell(x,y);
	Piece cellPiece = cell->getPiece();

	std::cout<<"Player "<<this->playerID<<std::endl;
	cout<<"Cell has "<<cellPiece<<endl;
    if(cellPiece == 2)
    {
		if(this->pieceCount == 0)
        {
            return NO_MORE_MOVES;
        }
		this->pieceCount--;
		bool victory = grid->UpdateGrid(x,y,this->p);
        if(this->playerID == 1)
        {
			if(victory == true)
                return PLAYER_ONE_WIN;
            else
                return PLAYER_TWO_CHANCE;
        }
		if(this->playerID == 2)
        {
			if(victory == true)
                return PLAYER_TWO_WIN;
            else
                return PLAYER_ONE_CHANCE;
        }
    }
    return INVALID_MOVE;
}

Player::~Player()
{
}