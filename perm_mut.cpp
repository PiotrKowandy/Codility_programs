

/*
Author: Piotr Kowañdy
Description: Perm missing element in array.
Version: 1.0
*/

#include <algorithm>

#include <vector>





int solution(vector<int> &A){


	int length = A.size();

	int found =0;

	sort(A.begin(), A.end());

	int actual=0;

    
	if (A[actual] != A[actual+1]){

        	for (int i=0; i < length-1; i++){

            	if (A[i] != i+1){

                	found =0;

               	 	break;

        		}
 
	        	else found =1;

       		}


    	}

    	else{

		return 0;


    	}

	return found;


}



int main (int argc, char *argv[]){

	vector<int> vect;
	vect.push_back(4);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);

	cout << "Perm check is: " << solution(vect) << " \n";

	return 0;
}


