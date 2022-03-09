#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"
#include "Player.h"
#include "Enums.h"

class Player;
class Cell;

using namespace std;
class Grid
{
private:
    /* data */
    vector<vector<Cell*> > cells;
public:
    Grid(/* args */);
    Cell* getCell(int x, int y);
    bool UpdateGrid(int x,int y, Piece p);
    bool CheckVictory(int x,int y,Piece p);
    void PrintGrid();
    ~Grid();
};
#endif