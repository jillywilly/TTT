// TTT.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "board.h"

#include <iostream>
using namespace std;

int main()
{
	int current_player = 1;
	Board tBoard;
	int winner = 0;

	while (Board::getCurrentMove() < 9) {
		tBoard.printBoard();
		tBoard.makeMove(current_player);
		if (tBoard.checkWin(current_player)) {
			cout << "Player " << current_player
				<< " Wins!" << endl;
			winner = current_player;
			tBoard.printBoard();
			break;
		}
		else {
			if (current_player == 1)
				current_player = 2;
			else 
				current_player = 1;

		}
	}
		return 0;
	}

