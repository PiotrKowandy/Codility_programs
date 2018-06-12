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
    for (int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

vector<int> solution(int N, vector<int> &A){
    vector<int> new_A(N);
    int length_A = A.size();
	
    if (length > 1){
    	vector<int>::iterator max_el;

    	for (int i=0; i < length_A; i++){

        	if (A[i] < N) new_A[A[i]-1]++;
        	else{
            	max_el = max_element(new_A.begin(), new_A.end());
            	for (int j=0; j < N; j++){
                	new_A[j] = *max_el;
            	}
        	}
    	}
    }
    else{
	new_A[0] =1;
    }
    return new_A;
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


	cout << "Give me N: ";
	int N=0;
	cin >> N;
	vector<int> new_vect;
	new_vect = solution(N, vect);
	show_vector(new_vect);


	return 0;
}
