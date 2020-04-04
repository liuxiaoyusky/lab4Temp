#include "lab4.h"

//TODO: not work for cannot input 11,11 10,10 ......
int main(void) {
	TicTacToeGame TicTacToe;

	//Rect.setDimissions(5, 7);

	// Print the area of the object.
	cout << "Total game pieces: " << TicTacToe.getGameNums() << endl;
	TicTacToe.play();
	////Rect.setDimissions(5, 8);
	////cout << "Total game pieces: " << Rect.getGameNums() << endl;
	//vector <unsigned int> step{ 0,0 };
	//step[1] = 1;
	//cout << step[1] << endl;
	//changeVec(step);
	//cout << step[1] << endl;

	return 0;
}

//int changeVec(vector <unsigned int> &vec) {
//	vec[1] = 2;
//	return 1;
//}