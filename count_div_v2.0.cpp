/*
Author: Piotr Kowañdy
Description: Count div
Version: 2.0
*/

#include <iostream>
using namespace std;


int solution (int A, int B, int K){
    int found = 0;
    if (B>=A && K>0){
        if (((B-A)%K)==0) found = (B-A)/K;
        else found = ((B-A)/K)+1;
    }
    return found;
}


int main (int argc, char *argv[]){
    int found = solution(6, 11, 2);
    cout << "Count div is: " << found << "\n";
    return 0;
}
