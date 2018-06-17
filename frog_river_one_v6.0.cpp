/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 6.0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void show_vector(vector<int> &vect){
        for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
        cout << "\n";
}



int solution(int X, vector<int> &A) {
    int you_can_go=0;
    int missing=0;
    int length = A.size();
    int temp=0;
    if (length > 1){
        while (you_can_go < X){
                if (you_can_go < X){
                    if (A[length-1] < X+1 && A[length-1] > 0){
                        temp = length-1;
                        you_can_go++;
                        for (int i=length-2; i> 0; i--){
                            if (A[i] == A[temp]) missing++;
                        }
                    }
                    if (missing != 0) you_can_go = temp-1;
                }
                length--;
        }
    }
    else{
        if (A[length] == length+1) you_can_go = 0;
        else you_can_go = -1;
    }
    return you_can_go;
}


int main (int argc, char *argv[]){

    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


