#pragma once
class Board {
private:
	int board[9];
	static int currentMove;

public:
	Board();
	static int getCurrentMove();
	void printBoard();
	bool makeMove(int player_num);
	bool checkWin(int player_num);
};