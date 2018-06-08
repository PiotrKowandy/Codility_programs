/*
Author: Piotr Kowañdy
Description: Missing integer - founding the lowest missing integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show_vector(vector<int> &A){
	int length = A.size();
	for (int i=0; i<length; i++){
		cout << A[i] << " ";
	}
	cout << "\n";
}

int solution (vector<int> &A){

	sort(A.begin(), A.end());
	vector<int>::iterator ptr;
	ptr = unique(A.begin(), A.end());
	A.resize(distance(A.begin(), ptr));

	show_vector(A);
	int length = A.size(), found=0;

	vector<int> B;

	for (int i=0; i < length; i++) if (A[i] > 0) B.push_back(A[i]);

	int length_b = B.size();
	
	if (length_b > 0){
		for (int i=0; i < B[length_b-1]; i++){
			if (i+1 != B[i]){
				found = i+1;
				break;
			}
		}
		if (found ==0) found = B[length_b-1]+1; 
	}
	else found =1;
	return found;	
}

int main (int argc, char *argv[]){

	vector<int> vect;
	vect.push_back(5);
	vect.push_back(-4);
	vect.push_back(6);

	int lowest = solution(vect);
	cout << "The lowest missing integer is: " << lowest << "\n";

	return 0;
}
