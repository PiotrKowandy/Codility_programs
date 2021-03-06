/*


Bob is about to go on a trip. But first he needs to take care of his supply of socks. Each sock has its own color. Bob wants to take as many pairs of clean socks as possible (both socks in the pair should be of the same color).

Socks are divided into two drawers: clean and dirty socks. Bob has time for only one laundry and his washing machine can clean at most K socks. He wants to pick socks for laundering in such a way that after washing he will have a maximal number of clean, same-colored pairs of socks. It is possible that some socks cannot be paired with any other sock, because Bob may have lost some socks over the years.

Bob has exactly N clean and M dirty socks, which are described in arrays C and D, respectively. The colors of the socks are represented as integers (equal numbers representing identical colors).

For example, given four clean socks and five dirty socks:

If Bob's washing machine can clean at most K = 2 socks, then he can take a maximum of three pairs of clean socks. He can wash one red sock and one green sock, numbered 1 and 2 respectively. Then he will have two pairs of red socks and one pair of green socks.

Write a function:

    int solution(int K, vector<int> &C, vector<int> &D);

that, given an integer K (the number of socks that the washing machine can clean), two arrays C and D (containing the color representations of N clean and M dirty socks respectively), returns the maximum number of pairs of socks that Bob can take on the trip.

For example, given K = 2, C = [1, 2, 1, 1] and D = [1, 4, 3, 2, 4], the function should return 3, as explained above.

Assume that:

        K is an integer within the range [0..50];
        each element of arrays C, D is an integer within the range [1..50];
        C and D are not empty and each of them contains at most 50 elements.

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
Copyright 2009–2019 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void show_vector (std::vector<int> &V){

	for (int a : V) std::cout<< a << " ";
	std::cout<< "\n";
}

void show_vector2 (std::vector<int> &V){

	int length = V.size();
	for (int i=0; i < length; i++) std::cout<< V[i] << " ";
	std::cout<< "\n";
}

bool find_pair (int i, std::vector<int> &V, int &result){
    int length = V.size();
    bool changed =false;
    if (length > 1){
        if (V[i] == V[i+1]){
            V[i] = 0;
            V[i+1] = 0;
            result +=1;
            changed = true;
        }
    }
    return changed;
}

int solution (int K, std::vector<int> &C, std::vector<int> &D){

	int result=0, length = C.size(), length_D = D.size();
	std::sort(C.begin(), C.end());

	for (int i=0; i<length; i++){
        if (C[i] != 0){
            if (find_pair(i, C, result) == false){
                for (int j=0; j<length_D; j++){
                        if (C[i] == D[j]){
                            if (K > 0){
                                result +=1;
                                K -=1;
                                C[i] = 0;
                                D[j] = 0;
                                break;
                            }
                        }

                }
            }
        }
	}

	return result;
}

int main (int argc, char *argv[]){

	int K = 2, result = 0;
	std::vector<int> C = {1,2,1,1}, D = {1,4,3,2,4};
	std::cout<< "\nNumber of socks in one wash: " << K << "\n";
	std::cout<< "Clean socks:                 ";
	show_vector(C);
	std::cout<< "Dirty socks:                 ";
	show_vector(D);
	result = solution(K, C, D);
	std::cout<< "\nNumber of clean socks after one washing is: " << result << "\n\n";

	return 0;
}
