/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 5.0
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
    int length = A.size();
    int temp=0;
    int position=0;
    int missing=0;
    int max_pos=0;

   while (temp < X){
        if (A[position] == temp+1){
            if (position > max_pos) max_pos= position;
            you_can_go++;
            temp++;
            position=0;
            if (missing >0 ){
                    position -=missing;
            }
            else{
                position++;
            }

        }
        else{
            missing++;
            position++;
        }
        missing=0;
   }
    you_can_go =max_pos;
    return you_can_go;
}


int main (int argc, char *argv[]){

    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


