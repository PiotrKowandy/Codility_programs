/*
Author: Piotr Kowańdy
Description: Odd occurrences in array - Program is showing one unpaired digit.
*/

#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

//----------------------------------------------------------------------
// Printing all elements of vector on console.
void show_vector(vector<int> &vect){

	for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << "\n";
}

// Function return one unpaired digit.
int solution (vector<int> &vect){

    int found =0;
    int max = vect.size();
    sort(vect.begin(), vect.end());

    for (int i=0; i < max; i +=2){
        if (vect[i] != vect[i+1]){
            found = vect[i];
            break;
        }
    }

    return found;
}
//----------------------------------------------------------------------

// Main function. Adding elements to vector. Initialization of solution function.
int main (int argc, char *argv[]){

	vector<int> vect;
	vect.push_back(9);
	vect.push_back(3);
	vect.push_back(9);
	vect.push_back(3);
	vect.push_back(9);
	vect.push_back(7);
	vect.push_back(9);

	cout << "\nVector: ";
	show_vector(vect);
	int found = solution(vect);
	cout << "Unpaired digit is: " <<  found << " \n\n";

	return 0;
}

