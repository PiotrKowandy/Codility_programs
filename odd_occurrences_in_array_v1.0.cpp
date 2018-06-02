/*
Author: Piotr Kowańdy
Description: Odd occurrences in array - Program is showing one unpaired digit.
*/

#include <iostream>
#include <vector>

using namespace std;

//----------------------------------------------------------------------
// Printing all elements of vector on console.
void show_vector(vector<int> &vect){

	for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << "\n";
}

// Function return one unpaired digit.
int solution (vector<int> &vect){

	int found=0, number_of_pair=0;
	vector<bool> checked(vect.size());

	for (int i=0; i < vect.size(); i++){
		for (int j = i+1; j < vect.size(); j++){
			if (vect[i] == vect[j] && checked[i] == false && checked[j] == false){
				number_of_pair++;
				checked[i] = true;
				checked[j] = true;
				cout << "\nPair number: "<< number_of_pair << " --- vect[" << i << "]" << " and vect[" << j << "] = " << vect[j] << "\n";
			}
		}
	}

	cout << " \n";
	for (int i=0; i < vect.size(); i++) if (checked[i] == false) found = vect[i];
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



/* another solution function
int solution(vector<int> &A) {
    int max = A.size();
    vector<bool> Check(max);
    int found = 0;
    for (int i=0; i<max; i++){
        for (int j = i+1; j<max; j++){
            if (A[i]==A[j] && Check[i] == Check[j]){
                Check[i] = true;
                Check[j] = true;
            }
            else if (Check[i] == false){
                found = A[i];
            }
        }
    }
    return found;
}
*/
