/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 3.0
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vector(vector<int> &vect){

        for (int i=0; i < vect.size(); i++){
            cout << vect[i] << " ";
        }
        cout << "\n";
}

void show_vector_bool(vector<bool> &vect){

        for (int i=0; i < vect.size(); i++){
            cout << vect[i] << " ";
        }
        cout << "\n";
}


bool is_full(vector<bool> &time_vector){
    bool full = false;
    int length = time_vector.size();
    for (int i=0; i<length; i++) if (time_vector[i] != false) full=true;
    return full;
}

int solution(int X, vector<int> &A) {
    int time_to_jump=0;
    int length = A.size();
    vector<bool> time_vector(X);

    for (int i=0; i<length; i++){
        if (time_vector[A[i]] == false) time_vector[A[i]-1] = true;
        if (is_full(time_vector)) time_to_jump=i-1;
    }
    return time_to_jump;
}


int main (int argc, char *argv[]){

    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


