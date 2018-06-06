/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 2.0
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

int solution(int X, vector<int> &A) {
  int length = A.size();
    int found =0, position=0;

    if (X <= length){

        if (X != length){
            vector<bool> vect_bool(length);

            for (int i=0; i < length; i++){
                if (vect_bool[A[i]] == false && found < X){
                    vect_bool[A[i]-1] = true;
                    found++;
                }
                std::cout << found << "\n";
                if (found == X){
                    position = i;
                    break;
                }
                else{
                    position = -1;
                }

            }
            if (position ==0) position = -1;
        }
        else{
            position = 0;
        }
    }
    else{
        position = -1;
    }
    return position;

}


int main (int argc, char *argv[]){

    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


