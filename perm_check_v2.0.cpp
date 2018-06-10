/*
Author: Piotr Kowañdy
Description: Perm check
Version: 2.0
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void show_vector(vector<int> &A){
    int length = A.size();
    for (int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

int solution(vector<int> &A){

	int found =0;
	sort(A.begin(), A.end());
	int actual=0;

    show_vector(A);
    int length = A.size();
    if (length > 1){
        for (int i=0; i < length; i++){
            if (A[i] != i+1 || A[i] == actual){
                found =0;
                break;
            }
            else found = 1;
            actual = A[i];
        }
    }
    else{
        if (A[0] == 1) found = 1;
        else found =0;
    }
	return found;
}



int main (int argc, char *argv[]){
	vector<int> vect;
	vect.push_back(3);
	vect.push_back(1);
	vect.push_back(-2);
	vect.push_back(2);
    int found = solution(vect);
	cout << "Perm check is: " << found << " \n";

	return 0;
}


