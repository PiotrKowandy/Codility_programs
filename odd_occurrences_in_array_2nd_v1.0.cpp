/*
Author: Piotr Kowańdy
Description: Odd occurrences in array - Program is showing one unpaired digit.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//----------------------------------------------------------------------
// Printing all elements of vector on console.
void show_vector(vector<int> &vect){

	for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << "\n";
}

int solution (vector<int> &A){
    int one_count =0, it=0;
    do{
         if (std::count (A.begin(), A.end(), A[it]) == 1){
                one_count = 1;
                break;
         }
         else it++;
    }
    while(one_count != 1);
    return A[it];
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

