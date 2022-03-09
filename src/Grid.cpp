#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
    for(int i = 0; i < 3; i++)
    {
        vector<Cell*> tmp;
		for(int j = 0; j < 3; j++)
		{
			Cell* cell = new Cell();
			tmp.push_back(cell);
		}
		this->cells.push_back(tmp);
    }
}

Cell* Grid::getCell(int x,int y)
{
    return cells[x][y];
}

bool Grid::CheckVictory(int x,int y, Piece p)
{
    bool victory = 0;
    //checking row.
    int i = 0;
    while(i < 3 && cells[x][i]->getPiece() == p)
    {
        i++;
        if(i == 3)
            return true;
    }
    //checking column.
    int j = 0;
    while(j < 3 && cells[j][y]->getPiece() == p)
    {
        j++;
        if(j == 3)
            return true;
    }
    //check diagonal only if any diagonal element is affected.
    if(x == y || x+y == 2)
    {
        //checking first diagonal.
        int i = 0;
        int j = 0;
        while( (i < 3 && j < 3 )&& cells[i][j]->getPiece() == p)
        {
            j++;
            i++;
            if(i == 3)
                return true;
        }
        //checking second diagonal.
        i = 0;
        j = 2;
        while((i < 3 && j > -1) && cells[i][j]->getPiece() ==p)
        {
            i++;
            j--;
            if(i == 3)
                return true;
        }
    }
    return victory;
}

bool Grid::UpdateGrid(int x, int y,Piece p)
{
    cells[x][y]->setPiece(p);
    return CheckVictory(x,y,p);
}

void Grid::PrintGrid()
{
	string s;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            Piece p = this->cells[i][j]->getPiece();
            if(p == 2)
			{
				char tmpr = '_';
				s.push_back(tmpr);
				s.push_back(' ');
			}
            else
            {
                s.push_back(p);
				s.push_back(' ');
            }
            if(j == 2)
                s.push_back('\n');
        }
    }
	cout<<s<<endl;
}

Grid::~Grid()
{
}