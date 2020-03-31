#include "lab3_project.h"

int usage(const char* filename) {
	cout << "Usage:" << endl;
	cout<< "For two players, please input two parameters:" << endl << filename << " TicTacToe" << endl;
	cout<< "For three players, please input three parameters:" << endl << filename << " TicTacToe" <<" auto_player"<<endl;
	cout << "enumeration labels :" << endl;
	cout << "piece_color { O = 0, X = 1, empty=3, invalid = -1, noColor = -2 }" << endl;
	cout << "return_values { success = 0, quit = -2, failReadDimension = -3, noWin = -4, gaming = -5, invalidInput = 2, piecesNotMatch = 5 }" << endl;
	return return_values::invalidInput;
}

int main(int argc, char* argv[]) {

	status = return_values::success;
	if (argc < 2 || argc>3) {
		status = return_values::invalidInput;
	}
	else if (string(argv[input_indices::input_game_name])!="TicTacToe") {
		status = return_values::invalidInput;
	}
	else if (argc==3 && string(argv[input_indices::input_auto_player]) != "auto_player") {
		status = return_values::invalidInput;
	}

	if (status) {
	usage(argv[input_indices::program_name]);
	cout << "Invalid input, return error code: " << status << endl;
	return status;
}


	TicTacToeGame game;
	if (argc == 3) {
		game.auto_play = true;
	}
	status = game.play();
	cout << "Thanks for playing."<<endl;
	return status;
}

