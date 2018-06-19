/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 9.0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void show_vector(vector<int> &vect){
        for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
        cout << "\n";
}

int find_element(vector<int> &A, int X,  int length){
    int position=-1;
    for (int i=0; i < length; i++){
        if (A[i] == X){
            return i;
            break;
        }
    }
    return position;
}


int solution(int X, vector<int> &A) {
    int you_can_go = 0;
    int length = A.size();

    if (length < 2){
        if (A[0] == X) you_can_go=0;
        else return -1;
    }
    else{
        if (length > X){
            int mis = 0;
            for (int i=0; i<X; i++){
                mis = find_element(A, i+1, length);
                if (mis == -1){
                    return -1;
                    break;
                }
                else {
                    if (mis >= you_can_go) you_can_go = mis;
                }
            }
        }
        else{
             return -1;
        }
    }
    return you_can_go;
}


int main (int argc, char *argv[]){
    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


