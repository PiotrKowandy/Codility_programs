/*
Author: Piotr Kowañdy
Description: Max counters
2nd, Version: 4.0
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
    int length=A.size(), length2=vec_found.size(), max_el=0, check_max=0;

    for(int i = 0 ; i < length ; i++){
        if (A[i] == N+1) max_el = check_max;
        else{
            if (vec_found[A[i]-1] < max_el) vec_found[A[i]-1] = max_el;
            vec_found[A[i]-1]++;
            if (check_max < vec_found[A[i]-1]) check_max = vec_found[A[i]-1];
        }
    }

    for(int i = 0 ; i < length2 ; i++) if(vec_found[i] < max_el)  vec_found[i] = max_el;

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
