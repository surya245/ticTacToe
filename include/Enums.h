#ifndef ENUMS_H
#define ENUMS_H
enum Piece
{
    X,O,EMPTY
};

enum GameStatus
{
    PLAYER_ONE_CHANCE,
    PLAYER_TWO_CHANCE,
    PLAYER_ONE_WIN,
    PLAYER_TWO_WIN,
    NO_MORE_MOVES,
	INVALID_MOVE
};

#endif
