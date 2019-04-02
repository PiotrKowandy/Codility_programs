/*
Author: Piotr Kowañdy
Description: Frog river one
2nd, Version: 2.0
*/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;

void show_vect(vector<int> &A){
    int length = A.size();
    for (int i=0; i < length; i++){
        cout<< A[i] << " ";
    }
    cout << "\n";
}

int solution (int X, std::vector<int> &A){
        int ready2go=0;
        show_vect(A);
        std::cout<< "X = " << X << "\n\n";
        int length = A.size();

        if ((X == 1) && (A[0]== 1)) ready2go = 0;
        else if (length < X) ready2go = -1;
        else{
                int frog_position=0;
                bool applicable=false;
                while ((X != frog_position) || (applicable == false)){
                        applicable=false;
                        for (int i=0; i<length; i++){
                                if (A[i] == frog_position+1){
                                        frog_position++;
                                        if (ready2go<i) ready2go=i;
                                        applicable=true;
                                        break;
                                }
                        }
                        if (applicable ==false){
                                ready2go=-1;
                                break;
                        }
                }
        }
        return ready2go;
}



int main (int argc, char *argv[]){

	vector<int> vect= {1,3,1,4,2,3,5,4};
	int X=5, found_second=0;
	found_second = solution(X, vect);
	cout<< "Time when all leafs will be on place is: " << found_second << "\n";

	return 0;
}
