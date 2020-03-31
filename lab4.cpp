#include "lab4.h"
int main(void) {
	TicTacToeGame Rect;

	Rect.setDimissions(5, 7);

	// Print the area of the object.
	cout << "Total game pieces: " << Rect.getGameNums() << endl;
	Rect.setDimissions(5, 8);
	cout << "Total game pieces: " << Rect.getGameNums() << endl;
	return 0;
}