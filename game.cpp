#include"game.h"
using namespace std;

// Base class

Game::Game() {
}

void Game ::setDimissions(int row, int column) {
	rows = row;
	columns = column;
	piecesNum = row * column;
}

void Game::setWinNum(unsigned int num){
	winNum = num;
}



void Game::initGamePieces() {
		//make inner 9 boxs are nocolor, outter 16 boxes are empty and keep empty 
	for (unsigned int i = 0; i < piecesNum; i++) {
		gamePiece nullPiece;
		if (i <= (columns - 1) || i >= (piecesNum - columns) || i % columns == 0 || i % columns == (columns - 1)) {
			nullPiece.color = piece_color::empty;
		}
		else {
			nullPiece.color = piece_color::noColor;
		}
		nullPiece.display = " ";
		game_pieces.push_back(nullPiece);
	}
}

void Game::findIndex(unsigned int row, unsigned int column, unsigned int& index) {
	index = (rows - 1 - row) * columns + column;
}

int  Game::checkHorizontally(vector <unsigned int> step) {
	unsigned int row = step[0];
	unsigned int column = step[1];
	unsigned int index = 0;
	findIndex(row, column, index);
	int color = game_pieces[index].color;
	//check horizontally
	unsigned int count = 1;
	//check left
	unsigned int cur = index;
	for (unsigned int i = column - 1; i > 0; i--) {
		cur--;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}
	//check right
	cur = index;
	for (unsigned int i = column + 1; i < columns - 1; i++) {
		cur++;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}
	return count;
}

int  Game::checkVirtically(vector <unsigned int> step) {
	unsigned int row = step[0];
	unsigned int column = step[1];
	unsigned int index = 0;
	findIndex(row, column, index);
	int color = game_pieces[index].color;
	//check horizontally
	unsigned int count = 1;

	//check bottom
	unsigned int cur = index;
	for (unsigned int i = row - 1; i > 0; i--) {
		cur = cur + columns;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}
	//check top
	cur = index;
	for (unsigned int i = row + 1; i < rows - 1; i++) {
		cur = cur - columns;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}
	return count;
}

int  Game::checkDiagonal(vector <unsigned int> step) {
	unsigned int row = step[0];
	unsigned int column = step[1];
	unsigned int index = 0;
	findIndex(row, column, index);
	int color = game_pieces[index].color;

	unsigned int count = 1;

	//check right bottom
	unsigned int cur = index;
	unsigned int limit = min(row, columns - column - 1);
	for (unsigned int i = limit - 1; i > 0; i--) {
		cur = cur + columns + 1;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}
	//check left top
	cur = index;
	limit = min(rows - row - 1, column);
	for (unsigned int i = limit - 1; i > 0; i--) {
		cur = cur - columns - 1;
		if (game_pieces[cur].color != color) {
			break;
		}
		count++;
	}

	unsigned int count2 = 1;
	//check left bottom
	cur = index;
	limit = min(row, column);
	for (unsigned int i = limit - 1; i > 0; i--) {
		cur = cur + columns - 1;
		if (game_pieces[cur].color != color) {
			break;
		}
		count2++;
	}
	//check right top
	cur = index;
	limit = min(rows - row - 1, columns - column - 1);
	for (unsigned int i = limit - 1; i > 0; i--) {
		cur = cur - columns + 1;
		if (game_pieces[cur].color != color) {
			break;
		}
		count2++;
	}

	return max(count, count2);
}

bool Game::checkMoves() {
	//return true if no more valid moves spaces, otherwise return false
	for (unsigned int i = 0; i < piecesNum; i++) {
		if (i <= (columns - 1) || i >= (piecesNum - columns) || (i % columns) == 0 || (i % columns) == (columns - 1)) {
			continue;
		}
		else {
			if (game_pieces[i].color == piece_color::noColor) {
				return false;
			}
		}
	}
	return true;
}

string Game::colorEnumToString(int enumPiece_color) {
	switch (enumPiece_color) {
	case X:
		return "X";
	case O:
		return "O";
	case noColor:
		return "no color";
	default:
		return "invalid";
	}
}


int Game::auto_player(unsigned int& x, unsigned int& y) {
	x = rand() % 3 + 1;
	y = rand() % 3 + 1;
	return return_values::gaming;
}

int Game::done(vector <unsigned int>& step, unsigned int num) {
	unsigned int row = step[0];
	unsigned int column = step[1];
	unsigned int index = 0;
	findIndex(row, column, index);
	int color = game_pieces[index].color;

	unsigned int count = checkHorizontally(step);
	if (count >= num) {
		return color;
	}

	count = checkVirtically(step);
	if (count >= num) {
		return color;
	}

	count = checkDiagonal(step);
	if (count >= num) {
		return color;
	}


	//// This method should return the piece_color if 3-Xs or Os are in a vertical, horizontal or diagonal line; otherwise the method should return return_values::gaming.
	//	//check rows
	//	for (unsigned int i = 1; i <columns-1; i++) {
	//		int ans=checkWinRows(i,3);
	//		if (ans == piece_color::X || ans == piece_color::O) {
	//			return ans;
	//		}
	//	}

	//	//check columns
	//	for (unsigned int i = 1; i < rows - 1; i++) {
	//		int ans = checkWinColumns(i,3);
	//		if (ans == piece_color::X || ans == piece_color::O) {
	//			return ans;
	//		}
	//	}

	//	//check diagonals
	//	for (unsigned int i = 0; i < 2; i++) {
	//		//check exist; if exist, check color
	//		int ans = checkWinDiagonals(i);
	//		if (ans == piece_color::X || ans == piece_color::O) {
	//			return ans;
	//		}
	//	}

	return return_values::gaming;
}

int Game::draw(vector <unsigned int>& step) {
	//change return type of draw from bool to int
	//change to: return return_values::noWins if no winner and no space to move;
	//otherwise return correspoding winner or quit
	int ans = done(step, winNum);
	if (ans != return_values::gaming) {
		return ans;
	}
	else {
		if (checkMoves()) {
			return  return_values::noWin;
		}
		else {
			return return_values::gaming;
		}
	}
}

int Game::prompt(unsigned int& x, unsigned int& y, vector <unsigned int>& step) {
	cout << "\n" << "Type in \"quit\" to quit game.\nOr\n" <<
		"Enter two integers to move, seperated by comma, example: \"1,1\"" << endl;

	//save the input
	string temp;
	//cin >> temp;
	getline(cin, temp);

	//check quit, string.find will return the position of the substring if found
	//ref:
	if (temp.find("quit") != string::npos) {
		return return_values::quit;
	}

	//todo: modified to two digits
	if (temp.size() <3 || temp.size()>5) {
		cout << temp.size();
		return return_values::failReadDimension;
	}

	for (unsigned int i = 0; i < temp.size(); i++) {
		if (temp[i] == ',') {
			temp[i] = ' ';
			break;
		}
	}

	istringstream input(temp);

	if (input >> x >> y) {
		step[0] = x;
		step[1] = y;
		return return_values::success;
	}
	else {
		return return_values::failReadDimension;
	}

}

int  Game::turn(vector <unsigned int>& step) {

	//find which player, even to be X, odd to be O.
	turns++;
	unsigned int player = turns % 2;

	unsigned int row;
	unsigned int column;

	while (true) {
		int ans;
		if (auto_play && player == 0) {
			ans = auto_player(row, column);
		}
		else {
			ans = prompt(row, column, step);
		}
		if (ans == return_values::quit) {
			return return_values::quit;
		}
		else if (ans == return_values::failReadDimension) {
			cout << "Invalid input, try again." << endl;
		}
		else {
			//valid input, check if valid and in inner 9 boxes
			unsigned int index = (rows - 1 - row) * columns + column;
			if ((game_pieces[index].color == noColor)) {

				//update game pieces
				if (player == 1) {
					game_pieces[index].color = piece_color::X;
				}
				else {
					game_pieces[index].color = piece_color::O;
				}
				string pieceType = colorEnumToString(player);
				game_pieces[index].display = pieceType;
				game_pieces[index].name = pieceType;

				//print the board and update history
				cout << *this << endl;
				if (player == 1) {
					ostringstream add_on;
					add_on << row << "," << column << "; ";
					player1 += add_on.str();
					cout << player1 << endl;
				}
				else {
					ostringstream add_on;
					add_on << row << "," << column << "; ";
					player2 += add_on.str();
					cout << player2 << endl;
				}

				//return the type
				return return_values::gaming;
			}
			else {
				cout << "This is a invalid place, please put game piece into an empty inner 9 boxes.";
			}

		}
	}

}

int Game::play() {
	cout << *this << endl;
	int ans = return_values::gaming;
	vector <unsigned int> step{ 0,0 };
	while (ans == return_values::gaming) {
		cout << "step[0]  " << step[0] << endl;
		cout << "step[1]  " << step[1] << endl;

		//check quit
		if (turn(step) == return_values::quit) {
			return return_values::quit;
		}


		//check winners, continue or terminal
		int ans = draw(step);

		switch (ans) {
		case piece_color::X:
			cout << "PLayerX wins!" << endl;
			return return_values::success;
		case piece_color::O:
			cout << "PLayerO wins!" << endl;
			return return_values::success;
		case return_values::noWin:
			cout << "You played " << turns << " turns. No more moves. No winners!" << endl;
			return return_values::noWin;
		}

	}
}

ostream& operator<<(ostream& out, const Game& game) {
	//first 5 rows
	out << "\n";
	unsigned int curLineNum = 0;
	for (unsigned int i = 0; i < game.piecesNum; i += game.columns) {
		out << (game.rows - 1 - curLineNum);
		for (unsigned int j = 0; j < game.columns; j++) {
			out << " " << game.game_pieces[i + j].display;
		}
		out << endl;
		curLineNum++;
	}

	//coordinate at bottom
	out << " ";
	for (unsigned int i = 0; i < game.columns; i++) {
		out << " " << i;
	}

	out << "\n";

	return out;
}




//int Game::checkWinRows(unsigned int row) {
//	unsigned int cur = (rows - row-1)*columns+1;
//	piece_color color = game_pieces[cur].color;
//	for (unsigned int i = 2; i < columns-1; i++) {
//		cur++;
//		if (game_pieces[cur].color != color|| game_pieces[cur].color==piece_color::noColor) {
//			return return_values::piecesNotMatch;
//		}
//	}
//	//O=0  X=1 and noColor=-2, not match=5
//	return color;
//}
//
//int Game::checkWinColumns(unsigned int column) {
//	unsigned int cur = column+rows;
//	int color = game_pieces[cur].color;
//	for (unsigned int i = 2; i < rows-1; i++) {
//		cur += rows;
//		if (game_pieces[cur].color != color) {
//			return return_values::piecesNotMatch;
//		}
//	}
//	//X=0  O=1 and noColor=-2, not match=5
//	return color;
//}
//
//int Game::checkWinDiagonals(unsigned int diagonals) {
//	//diagonals : 
//	//0: from left top to right bottom,check 6,12,18; 
//	//1:left bottom to right top, check 8,12,16;
//
//	if (diagonals == 0) {
//		unsigned int loc = columns + 1;
//		int color = game_pieces[loc].color;
//		for (; loc < piecesNum - columns; loc = loc + columns + 1) {
//			if (game_pieces[loc].color != color) {
//				return return_values::piecesNotMatch;
//			}
//		}
//		return color;
//	}else{
//		unsigned int loc = columns*2 -2;
//		int color = game_pieces[loc].color;
//		for (; loc < piecesNum - columns; loc = loc + columns - 1) {
//			if (game_pieces[loc].color != color) {
//				return return_values::piecesNotMatch;
//			}
//		}
//		return color;
//	}
//}

