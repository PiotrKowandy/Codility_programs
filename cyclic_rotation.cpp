/*
Author: Piotr Kowańdy
Description: Cyclic rotation - function rotate array K times.
*/

#include <iostream>
#include <vector>

using namespace std;

//----------------------------------------------------------------------
// Below function is checking if all elements are the same.
bool that_same(vector<int> &vect){

	bool result=false;
	int temp=vect[0];

	for (int i=1; i< vect.size(); i++){			
		if (temp == vect[i]) result = true;
		else result = false;
	}

	return result;
}

// Is printing vector before rotation.
void show_vect (vector<int> &vect){	

	for (int i=0; i < vect.size(); i++){
		cout << vect[i] << " ";
	}

}

//Adding elements to vector.
void assign_elements(vector<int> &vect, int count){

	int element=0;

	for (int i=0; i< count; i++){
		cout << "\nGive me element number: " << i+1 << " ";
		cin >> element;
		vect.push_back(element);
	}

	cout << "\nAll elements have been added\n";

}

// This function is rotating array K times. 
vector<int> solution (vector<int> &vect, int K){

	if (that_same(vect) == true || vect.size() < 2 || K == 0){		// If all elements have that same value or in vector is only one digit, rotation is not necessary.
		return vect;	
	}
	else{
		K %= vect.size();					// Example If K=6 and size of vector=5, there is not necessary to do one full circle + 1. It is required only 1 rotation.
		for (int jump = 0; jump < K; jump++){
			int temp=0;
			temp = vect[vect.size()-1];		
			for (int i = vect.size(); i > 0; i--){
				vect[i-1] = vect[i-2];		
			}
			vect[0] = temp;
		}
		return vect;
	}	
}
//----------------------------------------------------------------------

// Main function. Adding elements to vector. Initialization of solution function.
int main (int argc, char *argv[]){

	cout << " \n\n";
	int exit=0, K = 0, elements = 0;
	vector<int> vect;	

	do{
		int which_case=0;		
		cout << "\n\n1 - Program will ask You about all elements and rotate count\n";
		cout << "2 - Strictly added elements to vector, You will can choose how many rotation will be.\n";
		cout << "---------------------------------------------------------------------------------------------\n";
		cout << "0 - End of program.\n";
		cout << "\nWhich case do You choose? \n";
		cin >> which_case;
		switch(which_case){
			case 1:{
				vect.erase(vect.begin(), vect.end());
				cout << "\nHow many rotate ? ";
				cin >> K;
				cout << "How many elements do You want? ";
				cin >> elements;
				if (elements > 0){
					assign_elements(vect, elements);
					cout << "\nVector before rotation: ";
					show_vect(vect);
					vect = solution (vect, K);
					cout << "\nVector after rotation: ";
					show_vect(vect);
				}
				else{
					cout << "Sorry, but vector is empty\n";
				}
				exit = 1;
				break;	
			}
			case 2:{
				vect.erase(vect.begin(), vect.end());
				vect.push_back(3);
				vect.push_back(6);
				vect.push_back(9);
				vect.push_back(1);
				vect.push_back(2);
				cout << "\nVector before rotation: ";
				show_vect(vect);
				cout << "\nHow many rotate ? ";
				cin >> K;
				vect = solution (vect, K);
				cout << "\nVector after rotation: ";
				show_vect(vect);
				exit = 2;
				break;	
			}
			case 0:{
				exit = 0;
				break;	
			}
		}
	}
	while(exit != 0);

	return 0;
}
