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
    for (int a=0; a< length; a++) cout << " " << A[a] << " ";
    cout << "\n\n";
}

vector<int> solution(int N, vector<int> &A){

    std::vector<int> vec_found(N);
    int counter=0, length=A.size(), max_el=0, check_max=0;;

    while(counter < length){
        if (A[counter] <= N && A[counter]>0){
            if (vec_found[A[counter]-1] < max_el) vec_found[A[counter]-1] = max_el;
            vec_found[A[counter]-1]++;
            if (vec_found[A[counter]-1] > check_max) check_max = vec_found[A[counter]-1];
        }
        else{
                max_el = check_max;
        }
        counter++;
    }

    for(int i = 0 ; i < length ; i++){
        if(vec_found[i] < max_el)  vec_found[i] = max_el;
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
