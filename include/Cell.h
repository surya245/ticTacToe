#ifndef CELL_H
#define CELL_H

#include "Player.h"
#include "Enums.h"
class Player;

using namespace std;

class Cell
{
private:
    Piece p;
public:
    Cell();
    void setPiece(Piece p);
    Piece getPiece();
    ~Cell();
};

#endif