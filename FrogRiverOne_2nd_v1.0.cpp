/*
Author: Piotr Kowañdy
Description: Frog river one
2nd, Version: 1.0
*/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;

void show_vector(vector<bool> &A){
    int length = A.size();
    for (int i=0; i < length; i++){
        cout<< A[i] << " ";
    }
    cout << "\n";
}

bool ready (vector<bool> &B){
    int length = B.size();
    if (std::count(B.begin(), B.end(), true) == length){
        show_vector(B);
        return true;
    }
    else{
        show_vector(B);
        return false;
    }
}

int solution(int X, vector<int> &A) {
    int you_can_go = 0;
    int length = A.size();

    if (length < 2){
        if (A[0] == X) return 0;
        else return -1;
    }
    else{
        if (length > X){
            vector<bool> found_vector(X);
            for (int i=0; i<length; i++){
                found_vector[A[i]-1] = true;
                if (ready(found_vector) == true) return i;
            }
        }
        else return -1;
    }
}



int main (int argc, char *argv[]){

	vector<int> vect= {1,3,1,4,2,3,5,4};

	int X=5, found_second=0;
	found_second = solution(X, vect);
	cout<< "Time when all leafs will be on place is: " << found_second << "\n";

	return 0;
}
