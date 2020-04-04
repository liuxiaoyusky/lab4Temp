//#include "lab4.h"
// pure virtual members can be called
// from the abstract base class
#include <iostream>
using namespace std;

class Game {
protected:
	int width, height;

public:
	void set_values(int a, int b)
	{
		width = a; height = b;
	}
	virtual void print(void) = 0;
	void play(void)
	{
		this->print();
	}
};

class CR : public Game {
public:
	void print(void)
	{
		cout << (width * height) << endl;
	}
};

class CT : public Game {
public:
	void print(void)
	{
		cout<< (width * height / 2)<<endl;
	}
};

int main() {
	CR rect;
	CT trgl;
	//TicTacToeGame ttt;
	Game* ppoly1 = &rect;
	Game* ppoly2 = &trgl;
	//Game* pttt = &ttt;
	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);
	//pttt->set_values(1, 1);
	ppoly1->play();
	ppoly2->print();
	//pttt->print();
	return 0;
}


//Game* Game::chooseGame(int argc, char* argv[]) {
//	char* temp = "TicTacToe";
//	if (argc == NUM_ARGS) {
//		//todo
//		if (strcmp(argv[1], temp) == 0) {
//			TicTacToeGame game;
//			return &game;
//		}
//	}
//	return 0;
//}



//int main(int argc, char * argv[]) {
//	//cout << Game::chooseGame(argc,argv) << endl;
///*	TicTacToeGame TicTacToe;
//	Game* game = &TicTacToe*/;
//	//Game* a = TicTacToeGame::&TicTacToe();
//	Game* game = Game::chooseGame(argc, argv);
//	game->play();
//
//	////Rect.setDimissions(5, 7);
//
//	//// Print the area of the object.
//	//cout << "Total game pieces: " << TicTacToe.getGameNums() << endl;
//	//TicTacToe.play();
//	////Rect.setDimissions(5, 8);
//	////cout << "Total game pieces: " << Rect.getGameNums() << endl;
//	//vector <unsigned int> step{ 0,0 };
//	//step[1] = 1;
//	//cout << step[1] << endl;
//	//changeVec(step);
//	//cout << step[1] << endl;
//
//	return 0;
//}

//Game* Game::chooseGame(int argc, char* argv[]) {
//	char* temp = "TicTacToe";
//	if (argc == NUM_ARGS) {
//		//todo
//		if (strcmp(argv[1], temp) == 0) {
//			TicTacToeGame game;
//			return &game;
//		}
//	}
//	return 0;
//}

//int changeVec(vector <unsigned int> &vec) {
//	vec[1] = 2;
//	return 1;
//}