/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 4.0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vector(vector<int> &vect){
        for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
        cout << "\n";
}

void show_vector_bool(vector<bool> &vect){
        for (int i=0; i < vect.size(); i++) cout << vect[i] << " ";
        cout << "\n";
}


int solution(int X, vector<int> &A) {
    int you_can_go=0;
    int length = A.size();
    vector<int>::iterator max_el;
    max_el = max_element(A.begin(), A.end());

    if (*max_el > length){
        you_can_go = -1;
    }
    else{
        for (int j=0; j<X; j++){
            for (int i=length; i>0; i--){
                if (A[i] == j+1){
                        A[i] =0;
                        break;
                }
            }
        }
        for (int i=length; i > 0; i--){
            if (A[i] == 0){
                you_can_go = i-1;
                break;
            }
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


