/*
A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

The answers to these M = 3 queries are as follows:

        The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
        The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
        The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.

Write a function:

    vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a vector of integers.

For example, given the string S = CAGCCTA and arrays P, Q such that:
    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6

the function should return the values [2, 4, 1], as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        M is an integer within the range [1..50,000];
        each element of arrays P, Q is an integer within the range [0..N − 1];
        P[K] ≤ Q[K], where 0 ≤ K < M;
        string S consists only of upper-case English letters A, C, G, T.

Copyright 2009–2019 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int decod (char &nucleodit){
	int number=0;
	enum Nucleo {A=1, C, G, T};
	switch (nucleodit){
		case 'A' :number = 1;
			break;
		case 'C' :number = 2;
			break;
		case 'G' :number = 3;
			break;
		case 'T' :number = 4;
			break;
	}
	return number;
}

int which_min (int P_elem, int Q_elem, std::string &new_string){

	int min = (P_elem >= Q_elem ? Q_elem : P_elem);
	int max = (P_elem <= Q_elem ? Q_elem : P_elem);

	std::cout<< "min: " << min << " max: " << max << " \n";
	std::cout<< "P_elem: " << P_elem << " Q_elem: " << Q_elem << " \n";


	int found=decod(new_string[min]);
	std::cout<< "decod(new_string[min]) = " << decod(new_string[min]) << " \n";
	
	for (int i=min; i<max+1; i++){
		std::cout<< "in loop: decod(new_string[i]) = " << decod(new_string[i]) << " \n";
		std::cout<< "found = " << found << " \n";
		if (found > decod(new_string[i])){
			found = decod(new_string[i]);
		} 
	}

	return found;
}

std::vector<int> solution (std::string &S, std::vector<int> &P, std::vector<int> &Q){
	int length = P.size();
	std::vector<int> result(length);

	for (int i=0; i<length; i++){
		std::cout<< "\n Iteratior i = " << i << " \n";
		std::cout<< "I'm sending S[P[i]] = " << S[P[i]] << " S[Q[i]]" << S[Q[i]] << "\n";
		std::cout<< "decod(S[P[i]]) = " << decod(S[P[i]]) << " decod(S[Q[i]])" << decod(S[Q[i]])<< "\n";
		result[i] = which_min(P[i], Q[i], S);
		std::cout<< "which_min (...) = " << which_min(P[i], Q[i], S ) << "\n";
		std::cout << "result[i] = " << result[i] << " \n";
		std::cout<< "End of iteration i = " << i << " \n\n";
	}

	return result;
}

void show_vector(std::vector<int> &Vector){
	int length = Vector.size();
	std::cout<< "\n";
	for (int i=0; i<length; i++) std::cout<< Vector[i] << " ";
	std::cout<< "\n\n";
}

int main (int argc, char *argv[]){

        std::string S = "CAGCCTA";
	std::vector<int> P = {2,5,0};
	std::vector<int> Q = {4,5,6};

	std::vector<int> final_vector;
	final_vector = solution(S, P, Q);
	show_vector(final_vector);

	return 0;
}




/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int decod (char &nucleodit){
        int number=0;
        enum Nucleo {A=1, C, G, T};
        switch (nucleodit){
                case 'A' :number = 1;
                        break;
                case 'C' :number = 2;
                        break;
                case 'G' :number = 3;
                        break;
                case 'T' :number = 4;
                        break;
        }
        return number;
}

int which_min (int P_elem, int Q_elem, std::string &new_string){
        int min = (P_elem >= Q_elem ? Q_elem : P_elem);
        int max = (P_elem <= Q_elem ? Q_elem : P_elem);
        int found=decod(new_string[min]);
        for (int i=min; i<max+1; i++) if (found > decod(new_string[i])) found = decod(new_string[i]);       
        return found;
}

std::vector<int> solution (std::string &S, std::vector<int> &P, std::vector<int> &Q){
        int length = P.size();
        std::vector<int> result(length);
        for (int i=0; i<length; i++) result[i] = which_min(P[i], Q[i], S);
        return result;
}

*/
