#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/* enumerations */
enum piece_color { O = 0, X = 1, empty = 3, invalid = -1, noColor = -2 };
enum return_values { success = 0, quit = -2, failReadDimension = -3, noWin = -4, gaming = -5, invalidInput = 2, piecesNotMatch = 5 };


struct gamePiece {
	piece_color color;
	string name;
	string display;
};



class Game {
public:
	void setDimissions(int row, int column);

protected:
	Game();
	int rows;
	int columns;
	//	unsigned int columns;						//columns of game board
//	unsigned int rows;							//rows of game board
//	unsigned int piecesNum;						//number of pieces can present on the board at most
//	vector <gamePiece> game_pieces;				//vector to same gamePiece
//	unsigned int turns;							//number of turns in the game
//	string player1 = "Player X: ";				//history moves of player1
//	string player2 = "Player O: ";				//history moves of player2
};