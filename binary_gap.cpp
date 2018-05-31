/*
Author: Piotr Kowańdy
Description: Binary gap - looking for max gap in binary representation of given number.
*/

#include <iostream>
#include <vector>

using namespace std;


//-----------------------------------------------------------------------------
//Function which is counting max number of zeros in number.
int solution (vector<int> &vect){
	int counter = 0, v_begin = 0, temp_counter=0;
	for (int i = vect.size(); i > 0; i--){			//from end to begin
	
		if (vect[i-1] == 0){
			if (v_begin == 1){
				temp_counter++;
			}
		}
		else{
			if (counter < temp_counter){		//in this condition is checking counter with temporary counter
				counter = temp_counter;
				temp_counter = 0;			
			}
			temp_counter = 0;
			v_begin =1;			
		}	
	}
	return counter;
}

//In this function given number is converted to binary which is save in vector.
void assign(vector<int> &vect, int n){
	do{
		(n % 2) ? vect.push_back(1) : vect.push_back(0); 
		n /=2;		
	}
	while(n != 0);
}

//Whole number is printed on console.
//First digit of number is the last element in vector. 
//That's why loop is launched from end.
void show_vector(vector<int> &vect){
	cout << "Binary representation: ";
	for (int i=vect.size(); i > 0; i--) cout << vect[i-1] << " ";	
	cout << "\n";
}
//-----------------------------------------------------------------------------

//Main function. In this part of code do-while loop is used to repeat step with new number.
int main (int argc, char *argv[]){	
	int exit=0, n = 0;
	vector<int> vect;
	do{
		vect.erase(vect.begin(), vect.end());		//cleaning elements in vector in next step of loop
		cout << "Give me a number \n" << "Number: ";
		cin >> n;
		assign(vect, n);
		show_vector(vect);
		cout << "GAP : " << solution(vect) << "\n";		
		cout << "-----------------\n" << "Exit - choose 0\n"; 
		cin >> exit;
	}
	while(exit !=0);
	return 0;
}
