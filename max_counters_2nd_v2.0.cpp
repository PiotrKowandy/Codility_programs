/*
Author: Piotr Kowañdy
Description: Max counters
Version: 2.0
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void show_vector(vector<int> &A){
    int length = A.size();
    cout << "\n\n";
    for (int a=0; a< length; a++) cout << " " << A[a] << " ";
    cout << "\n\n";
}

vector<int> solution(int N, vector<int> &A){

    std::vector<int> vec_found(N);
    int counter=0, length=A.size();

    while(counter < length){
        if (A[counter] <= N && A[counter]>0) vec_found[A[counter]-1]++;
        else std::fill(vec_found.begin(), vec_found.end(), *(max_element(vec_found.begin(), vec_found.end())));
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
