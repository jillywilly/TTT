#include "stdafx.h"
#include <iostream>
#include "board.h"


using namespace std;

int Board::currentMove = 0;

Board::Board() {
	for (int i = 0; i < 9; i++) {
		board[i] = 0;
	}
}

void Board::printBoard() {
	for (int c = 0; c < 3; c++) {
		cout << "   " << c;
	}
	cout << endl << endl;
	for (int r = 0; r < 3; r++) {
		cout << r << "  ";
		for (int c = 0; c < 3; c++) {
			if (board[r * 3 + c] == 0)
				cout << " . ";
			else if (board[r * 3 + c] == 1)
				cout << " x ";
			else
				cout << " o ";
		}
		cout << endl << endl;
	}
}

int Board::getCurrentMove() {
	return currentMove;

}


bool Board::makeMove(int player_num) {

	int row, col;
	bool valid = false;

	if (currentMove >= 9)
		return false;

	while (!valid) {
		cout << "Player no.:" << player_num << " make your move:" << endl;
		cout << "Row:";
		cin >> row;
		while (row < 0 || row > 2) {
			cout << "Enter 0, 1, or 2" << endl;
			cout << "Row:";
			cin >> row;
		}
		cout << "Col:";
		cin >> col;
		while (col < 0 || col > 2) {
			cout << "Enter 0, 1, or 2" << endl;
			cout << "Col:";
			cin >> col;
		}
		cout << "checking array position:" << row * 3 + col << endl;
		if (board[row * 3 + col] == 0) {
			board[row * 3 + col] = player_num; // to 1 or 2
			valid = true;
		}
		else
			cout << "invalid move " << endl;
	}
	currentMove++;
	return true;
}

bool Board::checkWin(int player_num){
	if (board[0] == player_num && board[1] == player_num && board[2] == player_num)
		return true;
	if (board[3] == player_num && board[4] == player_num && board[5] == player_num)
		return true;
	if (board[6] == player_num && board[7] == player_num && board[8] == player_num)
		return true;
	if (board[0] == player_num && board[3] == player_num && board[6] == player_num)
		return true;
	if (board[1] == player_num && board[4] == player_num && board[7] == player_num)
		return true;
	if (board[2] == player_num && board[5] == player_num && board[8] == player_num)
		return true;
	if (board[0] == player_num && board[4] == player_num && board[8] == player_num)
		return true;
	if (board[2] == player_num && board[4] == player_num && board[6] == player_num)
		return true;


	return false;
}
