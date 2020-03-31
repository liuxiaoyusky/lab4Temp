#include"tic-tac-toe.h"

TicTacToeGame::TicTacToeGame():height(3) {

}

int TicTacToeGame::getGameNums() {
	return (rows * columns*height);
}
//
//TicTacToeGame::TicTacToeGame()
////constructor
//	:columns(5), rows(5), piecesNum(25),auto_play(false)
//{
//	//make inner 9 boxs are nocolor, outter 16 boxes are empty and keep empty 
//	for (unsigned int i = 0; i < piecesNum; i++) {
//		gamePiece nullPiece;
//		if (i <= (columns - 1) || i >= (piecesNum - columns) || i % columns == 0 || i % columns == (columns - 1)) {
//			nullPiece.color = piece_color::empty;
//		}
//		else {
//			nullPiece.color = piece_color::noColor;
//		}
//		nullPiece.display = " ";
//		game_pieces.push_back(nullPiece);
//	}
//}
//
//	int TicTacToeGame::checkWinRows(unsigned int row) {
//		unsigned int cur = (rows - row-1)*columns+1;
//		piece_color color = game_pieces[cur].color;
//		for (unsigned int i = 2; i < columns-1; i++) {
//			cur++;
//			if (game_pieces[cur].color != color|| game_pieces[cur].color==piece_color::noColor) {
//				return return_values::piecesNotMatch;
//			}
//		}
//		//O=0  X=1 and noColor=-2, not match=5
//		return color;
//	}
//
//	int TicTacToeGame::checkWinColumns(unsigned int column) {
//		unsigned int cur = column+rows;
//		int color = game_pieces[cur].color;
//		for (unsigned int i = 2; i < rows-1; i++) {
//			cur += rows;
//			if (game_pieces[cur].color != color) {
//				return return_values::piecesNotMatch;
//			}
//		}
//		//X=0  O=1 and noColor=-2, not match=5
//		return color;
//	}
//
//	int TicTacToeGame::checkWinDiagonals(unsigned int diagonals) {
//		//diagonals : 
//		//0: from left top to right bottom,check 6,12,18; 
//		//1:left bottom to right top, check 8,12,16;
//
//		if (diagonals == 0) {
//			unsigned int loc = columns + 1;
//			int color = game_pieces[loc].color;
//			for (; loc < piecesNum - columns; loc = loc + columns + 1) {
//				if (game_pieces[loc].color != color) {
//					return return_values::piecesNotMatch;
//				}
//			}
//			return color;
//		}else{
//			unsigned int loc = columns*2 -2;
//			int color = game_pieces[loc].color;
//			for (; loc < piecesNum - columns; loc = loc + columns - 1) {
//				if (game_pieces[loc].color != color) {
//					return return_values::piecesNotMatch;
//				}
//			}
//			return color;
//		}
//	}
//
//
//	void TicTacToeGame::findIndex(unsigned int i, unsigned int& x, unsigned int& y) {
//		x = rows - 1 - i / columns;
//		y = i % rows;
//	}
//
//
//	bool TicTacToeGame::checkMoves() {
//		//return true if no more valid moves spaces, otherwise return false
//		for (unsigned int i = 0; i < piecesNum; i++) {
//			if (i <= (columns - 1) || i >= (piecesNum - columns) || (i % columns) == 0 || (i % columns) == (columns-1)) {
//				continue;
//			}
//			else {
//				if (game_pieces[i].color == piece_color::noColor) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//
//	//cheanged return type from bool to int, so we know the identity of the player if someone win
//int TicTacToeGame::done() {
//	// This method should return the piece_color if 3-Xs or Os are in a vertical, horizontal or diagonal line; otherwise the method should return return_values::gaming.
//		//check rows
//		for (unsigned int i = 1; i <columns-1; i++) {
//			int ans=checkWinRows(i);
//			if (ans == piece_color::X || ans == piece_color::O) {
//				return ans;
//			}
//		}
//
//		//check columns
//		for (unsigned int i = 1; i < rows - 1; i++) {
//			int ans = checkWinColumns(i);
//			if (ans == piece_color::X || ans == piece_color::O) {
//				return ans;
//			}
//		}
//
//		//check diagonals
//		for (unsigned int i = 0; i < 2; i++) {
//			//check exist; if exist, check color
//			int ans = checkWinDiagonals(i);
//			if (ans == piece_color::X || ans == piece_color::O) {
//				return ans;
//			}
//		}
//
//		return return_values::gaming;
//	}
// 
//int TicTacToeGame::draw() {
//	//change return type of draw from bool to int
//	//change to: return return_values::noWins if no winner and no space to move;
//	//otherwise return correspoding winner or quit
//	int ans = done();
//	if (ans!= return_values::gaming){
//		return ans;
//	}
//	else {
//		if (checkMoves()) {
//			return  return_values::noWin;
//		}
//		else {
//			return return_values::gaming;
//		}
//	}
//}
//
//int TicTacToeGame::prompt(unsigned int& x, unsigned int& y) {
//	cout << "\n" << "Type in \"quit\" to quit game.\nOr\n"<<
//		"Enter two integers to move, seperated by comma, example: \"1,1\"" << endl;
//	
//	//save the input
//	string temp;
//	//cin >> temp;
//	getline(cin, temp);
//
//	//check quit, string.find will return the position of the substring if found
//	//ref:
//	if (temp.find("quit")!=string::npos) {
//		return return_values::quit;
//	}
//
//	if (temp.size() != 3) {
//		//cout << temp.size();
//		return return_values::failReadDimension;
//	}
//
//	//convert comma to space if exist
//	for (unsigned int i = 0; i < temp.size(); i++) {
//		if (temp[i] == ',') {
//			temp[i] = ' ';
//		}
//	}
//	
//	istringstream input(temp);
//
//	if (input >> x >> y) {
//		return return_values::success;
//	}
//	else {
//		return return_values::failReadDimension;
//	}
//
//}
//
//int TicTacToeGame::auto_player(unsigned int& x, unsigned int& y) {
//	x = rand() % 3 + 1;
//	y = rand() % 3 + 1;
//	return return_values::gaming;
//}
//
//
//int  TicTacToeGame::turn() {
//	
//	//find which player, even to be X, odd to be O.
//	turns++;
//	unsigned int player = turns % 2;
//
//	unsigned int row;
//	unsigned int column;
//
//	while (true) {
//		int ans;
//		if (auto_play && player == 0) {
//			ans = auto_player(row,column);
//		}
//		else {
//			ans = prompt(row, column);
//		}
//		if (ans == return_values::quit) {
//			return return_values::quit;
//		}
//		else if (ans == return_values::failReadDimension) {
//			cout << "Invalid input, try again." << endl;
//		}
//		else {
//			//valid input, check if valid and in inner 9 boxes
//			unsigned int index = (rows-1-row) * columns + column;
//			if ((game_pieces[index].color == noColor)) {
//
//				//update game pieces
//				if (player == 1) {
//					game_pieces[index].color = piece_color::X;
//				}else{
//					game_pieces[index].color = piece_color::O;
//				}
//				string pieceType = colorEnumToString(player);
//				game_pieces[index].display = pieceType;
//				game_pieces[index].name = pieceType;
//
//				//print the board and update history
//				cout << *this << endl;
//				if (player == 1) {
//					ostringstream add_on;
//					add_on << row << "," << column<<"; ";
//					player1 += add_on.str();
//					cout << player1 << endl;
//				}
//				else {
//					ostringstream add_on;
//					add_on << row << "," << column << "; ";
//					player2 += add_on.str();
//					cout << player2 << endl;
//				}
//
//				//return the type
//				return return_values::gaming;
//			}
//			else{
//				cout << "This is a invalid place, please put game piece into an empty inner 9 boxes.";
//			}
//
//		}
//	}
//
//}
//
//int TicTacToeGame::play() {
//	cout << *this <<endl;
//	int ans = return_values::gaming;
//	while (ans == return_values::gaming) {
//
//		//check quit
//		if (turn() == return_values::quit) {
//			return return_values::quit;
//		}
//
//		
//		//check winners, continue or terminal
//		int ans = draw();
//		
//		switch (ans) {
//		case piece_color::X:
//			cout << "PLayerX wins!" << endl;
//			return return_values::success;
//		case piece_color::O:
//			cout << "PLayerO wins!" << endl;
//			return return_values::success;
//		case return_values::noWin:
//			cout << "You played "<<turns <<" turns. No more moves. No winners!" << endl;
//			return return_values::noWin;
//		}
//
//	}
//}
//
//string TicTacToeGame::colorEnumToString(int enumPiece_color) {
//	switch (enumPiece_color) {
//	case X:
//		return "X";
//	case O:
//		return "O";
//	case noColor:
//		return "no color";
//	default:
//		return "invalid";
//	}
//}
//
//ostream& operator<<(ostream& out, const TicTacToeGame& game) {
//	//first 5 rows
//	out << "\n";
//	unsigned int curLineNum = 0;
//	for (unsigned int i = 0; i < game.piecesNum; i+=game.columns) {
//		out << (game.rows - 1 - curLineNum);
//		for (unsigned int j = 0; j < game.columns; j++) {
//			out << " "<<game.game_pieces[i+j].display;
//		}
//		out <<endl;
//		curLineNum++;
//	}
//
//	//coordinate at bottom
//	out << " ";
//	for (unsigned int i = 0; i < game.columns; i++) {
//		out <<" "<< i;
//	}
//
//	out << "\n";
//
//	return out;
//}
//
