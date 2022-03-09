#include "Cell.h"

using namespace std;

Cell::Cell()
{
    this->p = EMPTY;
}

void Cell::setPiece(Piece p)
{
    this->p = p;
}

Piece Cell::getPiece()
{
    return this->p;
}
Cell::~Cell()
{
}