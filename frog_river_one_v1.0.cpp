/*
Author: Piotr Kowañdy
Description: Frog river one.
Version: 1.0
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
    int found = 0;
    int curr_pos =0;
    int sum_el=0;
    bool exist = false;

    for (int i=0; i<length; i++){
        if (A[i]==X){
            curr_pos = i;
            exist = true;
        }
        if (i < X-1) sum_el += i+1;
    }

    if (length > 1 && exist == true){
        A.resize(distance(A.begin(), A.begin()+curr_pos));
        sort(A.begin(), A.end());
        vector<int>::iterator ptr_uniq;
        ptr_uniq = unique(A.begin(), A.end());
        A.resize(distance(A.begin(), ptr_uniq));
        length = A.size();
        int curr_sum=0;
        for (int i=0; i<length; i++){
            curr_sum += A[i];
        }
        if (sum_el == curr_sum) found = curr_pos;
        else{
            found = -1;
        }

    }
    else{
        if (exist == true)found = 0;
        else{
            found =-1;
        }
    }
    return found;

}


int main (int argc, char *argv[]){

    vector<int> vect {1,3,1,4,2,3,5,4};
    show_vector(vect);

    cout << "Frog can walk thru river in second: " << solution(5, vect) << " \n";
    return 0;
}


