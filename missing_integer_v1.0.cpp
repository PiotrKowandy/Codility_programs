/*
Author: Piotr Kowañdy
Description: Missing integer.
Version: 1.0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vector(vector<int> &A){
    int length = A.size();
    for (int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

int solution (vector<int> &A){

    int found=0;
    int length = A.size();
    int length_old = A.size();

    show_vector(A);

    sort(A.begin(), A.end());
    vector<int>::iterator ptr;
    ptr = unique(A.begin(), A.end());
    A.resize(distance(A.begin(), ptr));

    length = A.size();

    show_vector(A);

    if (A[length -1] < 1) found = 1;
    else{
        int actual=0, i=0;
        do{
            if (length > 1){
                actual = A[i];
                i++;
                if (actual+1 < A[i])found=actual+1;
            }
            else{
                if (A[0] > 1) found = 1;
                else{
                    found=2;
                }
            }
        }
        while(found == 0 && i <= length);
        if (found ==0) found = length_old+1;
    }

    return found;
}

int main (int argc, char *argv[]){

    vector<int> vect;

    vect.push_back(1);
    vect.push_back(3);
    vect.push_back(6);
    vect.push_back(4);
    vect.push_back(1);
    vect.push_back(2);

    cout << "Lowest missing integer is: " << solution(vect) << "\n";

    return 0;
}


