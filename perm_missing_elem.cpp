/*
Author: Piotr Kowańdy
Description: Perm missing element in array.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//----------------------------------------------------------------------
// Printing all elements from vector.
void show_vector(vector<int> &vect){

	cout << "Vector: ";
	for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << "\n";

}

// Searching missing element in array.
int solution (vector<int> &A){

    int found =0, sum=0, sum_all=0;
    int length = A.size();

    if (length > 0){
        for (int i=0; i<length; i++) sum += A[i];
        for (int j=1; j<=length+1; j++) sum_all += j;
        found = sum_all-sum;
    }
    else found = 1;

	return found;
}
//----------------------------------------------------------------------

// Main function of program. We fill the vector with numbers.
int main (int argc, char *argv[]){

	vector<int> vect;
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(1);
	vect.push_back(5);

	show_vector(vect);

	int found = solution (vect);
	cout << "Missing element in this array is: " << found << "\n";

	return 0;
}
