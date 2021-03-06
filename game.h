#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "gamePieces.h"
using namespace std;

#define NUM_ARGS 2							// number of arguments required for default game



class Game {
	friend ostream& operator<<(ostream& out, const Game& game);
protected:
	unsigned int columns;						//columns of game board
	unsigned int rows;							//rows of game board
	unsigned int piecesNum;						//number of pieces can present on the board at most
	vector <gamePiece> game_pieces;				//vector to same gamePiece
	unsigned int turns;							//number of turns in the game
	string player1 = "Player X: ";				//history moves of player1
	string player2 = "Player O: ";				//history moves of player2

	//Game();
	void setDimissions(int row, int column);
	void setWinNum(unsigned int num);
	void initGamePieces();


	void findIndex(unsigned int row, unsigned int column, unsigned int& index);
	int checkHorizontally(vector <unsigned int> step);
	int checkVirtically(vector <unsigned int> step);
	int checkDiagonal(vector <unsigned int> step);
	unsigned int winNum;

	bool checkMoves();
	string colorEnumToString(int enumPiece_color);

	//virtual int area(void) = 0;
	//void print(void)
	//{
	//	cout << this->area() << endl;
	//}

public:
	bool auto_play;
	int auto_player(unsigned int& x, unsigned int& y);
	int done(vector <unsigned int>& step, unsigned int num);
	int draw(vector <unsigned int>& step);
	int prompt(unsigned int& x, unsigned int& y, vector <unsigned int>& step);
	int turn(vector <unsigned int>& step);
	int play();
	static Game* chooseGame(int argc, char* argv[]);
	void print();
	virtual int area() = 0;
	int width, height;
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
};