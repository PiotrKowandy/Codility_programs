/*
Author: Piotr Kowańdy
Description: Tape equilibrium - searching minimal difference of tapes sum.
Example:

 Vector: 3 1 2 4 3

 Pair number: 1:     3(3)  - 10(1+2+4+3) = 7
 Pair number: 2:     4(3+1)  -  9(2+4+3) = 5
 Pair number: 3:     6(3+1+2)  -  7(4+3) = 1
 Pair number: 4:     10(3+1+2+4) -  3(3) = 7

*/

#include <iostream>
#include <vector>
using namespace std;

//----------------------------------------------------------------------
// Printing all elements from vector.
void show_vector(vector<int> &vect){

	cout << "\nVector: ";
	for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
	cout << "\n\n";

}

// Searching minimal sum of difference.
int solution (vector<int> &A){

   int difference=0, temp_dif=0, first=0, second=0;
    int length = A.size();

    if (length > 0){
        for (int j=0; j<length; j++){
            second += A[j];
        }

        for (int i=0; i < length-1; i++){
            first += A[i];
            second -=A[i];
            temp_dif = second - first;
            if (temp_dif < 0) temp_dif *=(-1);
            if (difference == 0 && i==0) difference = temp_dif;
            else{
                if (difference > temp_dif){
                    difference = temp_dif;
                }
            }
        }
    }
    else{
            difference =0;
    }
    return difference;
}
//----------------------------------------------------------------------

int main (int argc, char *argv[]){

	vector<int> vect;

	vect.push_back(3);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(4);
	vect.push_back(3);

/*
	vect.push_back(5);
	vect.push_back(2);
	vect.push_back(7);
	vect.push_back(1);
	vect.push_back(3);
*/
	show_vector(vect);
	if (vect.size() > 1){
		int found = solution (vect);
		cout << "Minimal difference of that vector is: " << found << "\n\n";
	}
	else{
		cout << "In vector is only one element, difference isn't able to found.\n";
	}
	return 0;
}
