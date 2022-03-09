#include<iostream>
#include<string>
#include "Game.h"
#include "Player.h"
#include "Cell.h"
#include "Grid.h"
#include "Enums.h"

using namespace std;

int main(){
    
    Game game;
    GameStatus currStatus;
    cout<<"Enter Player details...\n";  
    char piece1;
    char piece2;
    string p1;
    string p2;

    cout<<"Player1 Name...\n";
    getline(cin,p1);
    cout<<"Player2 Name...\n";
    getline(cin,p2);
    cout<<"Enter Player1 piece (X or O)\n";
    cin>>piece1;
	getchar();

    while(1)
    {
		if(piece1 == 'X' || piece1 == 'O')
			break;
        cout<<"Invalid entry, Please enter again (X or O)...\n";
        cin>>piece1;
    }
	
    if(piece1 == 'X')
    {
        currStatus = PLAYER_ONE_CHANCE;
		game.setStatus(currStatus);
        piece2 = 'O';
    }
    else
    {
        piece2 = 'X';
        currStatus = PLAYER_TWO_CHANCE;
		game.setStatus(currStatus);
    }

    cout<<"Player2 gets "<<piece2<<"...\n\n";

    Piece pc1 = static_cast<Piece>(piece1);
    Piece pc2 = static_cast<Piece>(piece2);
    Player P1(1,p1,pc1,&game); // id,name,piece_type,game.
    Player P2(2,p2,pc2,&game);
    
    game.setPlayers(P1);
    game.setPlayers(P2);
    
    Grid* grid = game.getGrid();
    grid->PrintGrid();

    string inputMoves;
	int x,y;

    while(1)
    {
		cout<<game.getStatus()<<endl;
        
		if(game.getStatus() == 0)
        {
			getline(cin,inputMoves);
			if(inputMoves == "exit")
				return 0;
			x = inputMoves[0] - '0';
			y = inputMoves[2] - '0';
			x--;
			y--;
            game.setStatus(P1.move(x,y));
			while(game.getStatus() == 5)
			{
				cout<<"INVALID MOVE\n";
				getline(cin,inputMoves);
				if(inputMoves == "exit")
					return 0;
				x = inputMoves[0] - '0';
				y = inputMoves[2] - '0';
				x--;
				y--;
				game.setStatus(P1.move(x,y));
			}

            grid->PrintGrid();
        }
		if(game.getStatus() == 1)
        {
			getline(cin,inputMoves);
			if(inputMoves == "exit")
				break;
			x = inputMoves[0] - '0';
			y = inputMoves[2] - '0';
			x--;
			y--;
            game.setStatus(P2.move(x,y));
			while(game.getStatus() == 5)
			{
				cout<<"INVALID MOVE\n";
				getline(cin,inputMoves);
				if(inputMoves == "exit")
					break;
				x = inputMoves[0] - '0';
				y = inputMoves[2] - '0';
				x--;
				y--;
				game.setStatus(P2.move(x,y));
			}
			grid->PrintGrid();
		}
        if(game.getStatus() == 2)
        {
            cout<<p1<<" Won!!!!\n";
            break;
        }
        if(game.getStatus() == 3)
        {
            cout<<p2<<" Won!!!!\n";
            break;
        }
        if(game.getStatus() == 4)
        {
            cout<<"Game OVER!!!";
            break;
        }

    }
    return 0;
}