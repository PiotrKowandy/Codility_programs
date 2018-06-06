/*
Author: Piotr Kowañdy
Description: Distinct.
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


int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int>::iterator ptr_uniq;
    ptr_uniq = unique(A.begin(), A.end());
    A.resize(distance(A.begin(), ptr_uniq));
    return A.size();
}


int main (int argc, char *argv[]){

    vector<int> vect {2,1,1,2,3,1};
    show_vector(vect);

    cout << "Distinct: " << solution(vect) << " \n";
    return 0;
}
