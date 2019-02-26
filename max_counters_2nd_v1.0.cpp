/*
Author: Piotr Kowañdy
Description: Max counters
Version: 1.0
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void show_vector(vector<int> &A){
    int length = A.size();
    cout << "\n\n";
    for (int a=0; a< length; a++){
        cout << " " << A[a] << " ";
    }
    cout << "\n\n";
}

void add_max (vector<int> &A, int &max_el){
    int length = A.size();
    for (int a=0; a< length; a++) A[a] = max_el;
}

vector<int> solution(int N, vector<int> &A){
    std::vector<int> vec_found(N);
    int counter=0, max_el=0;
    while(counter < A.size()){
        if (A[counter] <= N){
            cout << "\nCounter: " << counter << " I'm checking A[" << counter << "] = " << A[counter] << "\n";
            vec_found[A[counter]-1] = vec_found[A[counter]-1]+1;
            if (max_el < vec_found[A[counter]-1]) max_el = vec_found[A[counter]-1];
        }
        else{
            cout << "\nCounter: " << counter << " I'm checking A[" << counter << "] = " << A[counter] << "\n";
            add_max(vec_found, max_el);
        }
        show_vector(vec_found);
        counter++;
    }

    return vec_found;
}



int main (int argc, char *argv[]){

	vector<int> vect;
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(4);
	vect.push_back(6);
    vect.push_back(1);
	vect.push_back(4);
	vect.push_back(4);

	int N=5;
	vect = solution(N, vect);
	cout<< "This is our vector: ";
    show_vector(vect);

	return 0;
}
