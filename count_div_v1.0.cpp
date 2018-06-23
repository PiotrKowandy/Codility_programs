/*
Author: Piotr Kowañdy
Description: Count div
Version: 1.0
*/

#include <iostream>
using namespace std;


int solution (int A, int B, int K){
    int found=0;
    int start_position=0;

    if (A <= B && K <B && K >0){
        for (int i=A; i<= B; i++){
            if (i%K == 0){
                start_position = i;
                break;
            }
        }
        for (int i=start_position; i <= B; i+=K) found++;
    }

    return found;
}


int main (int argc, char *argv[]){
    int found = solution(6, 11, 2);
    cout << "Count div is: " << found << "\n";
    return 0;
}
