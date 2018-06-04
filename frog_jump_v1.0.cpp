/*
Author: Piotr Kowańdy
Description: Frog jumps - Program is counting how many jumps frog need to get to other side of road.
version: 1.0
*/

#include <iostream>
using namespace std;

// In this function while loop is counting jumps.
// When position of frog will be equal or greater than D, which is end of road, loop is end.

int solution (int X, int Y, int D){

	int counter=0;

	while (X < Y){
		X +=D;
		counter++;		// Counter of jumps.
	}

	return counter;
}


// Main function of program. 3 parameters are getting from user.
int main (int argc, char *argv[]){

	int X,Y,D;
	cout << "\nFrog want to get to other side of road.\n X - position of frog \n Y - end of road\n D - length of jump\n ";
	cout << "\nGive me X: ";
	cin >> X;
	cout << "\nGive me Y: ";
	cin >> Y;
	cout << "\nGive me D: ";
	cin >> D;
	int jumps = solution (X, Y, D);
	cout << "\nWith those parametres Frog need : " << jumps << " jumps to get on other side of road. \n\n";
	return 0;
}
