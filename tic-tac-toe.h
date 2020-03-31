#pragma once
#include"game.h"
class TicTacToeGame : public Game {
	//	friend ostream& operator<<(ostream& out, const TicTacToeGame& game);
public:
	int getGameNums();
	TicTacToeGame();
	//	bool auto_play;
//	int auto_player(unsigned int& x, unsigned int& y);
//	TicTacToeGame();
//	int done();
//	int draw();
//	int prompt(unsigned int& x, unsigned int& y);
//	int turn();
//	int play();
private:
	int height;
	//	unsigned int columns;						//columns of game board
	//	unsigned int rows;							//rows of game board
	//	unsigned int piecesNum;						//number of pieces can present on the board at most
	//	vector <gamePiece> game_pieces;				//vector to same gamePiece
	//	unsigned int turns;							//number of turns in the game
	//	string player1 = "Player X: ";				//history moves of player1
	//	string player2 = "Player O: ";				//history moves of player2
	//
	//	int checkWinRows(unsigned int row);
	//	int checkWinColumns(unsigned int columns);
	//	int checkWinDiagonals(unsigned int diagonals);
	//	void findIndex(unsigned int i, unsigned int& x, unsigned int& y);
	//	bool checkMoves();
	//	string colorEnumToString(int enumPiece_color);
};

ostream& operator<<(ostream& out, const TicTacToeGame& game);
