#pragma once
#include <string>
using namespace std;

/* enumerations */
enum piece_color { O = 0, X = 1, empty = 3, invalid = -1, noColor = -2 };
enum return_values { success = 0, quit = -2, failReadDimension = -3, noWin = -4, gaming = -5, invalidInput = 2, piecesNotMatch = 5 };


struct gamePiece {
	piece_color color;
	string name;
	string display;
};