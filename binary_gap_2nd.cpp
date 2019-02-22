#include <iostream>

using std::cout;
using std::endl;

bool non_power(int N){
    return (N && !(N & (N-1))) == true ? true : false;
}

int solution (int N){
    int found=0, temp=0;
    bool gap_begin=false;

    if (!(non_power(N)) && !(non_power(N+1))){
        while (N != 0){
            cout << " " << N%2 << " ";
            if ( N%2 == 1){
                if (temp>found){
                    found = temp;
                    temp=0;
                }
                temp=0;
                gap_begin=true;
            }
            else if (gap_begin) temp++;
            N/=2;
        }
    }
    return found;
}

auto main (int argc, char *argv[])->int{

    int N=561892;
    cout << "Biggest gap of zero is : " << solution(N) << "\n";

}
