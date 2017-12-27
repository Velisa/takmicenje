/*
	Solution to "Problem 13 - Large Sum" from projecteuler.net/archives
	
	Solved by Velisa Petricevic
*/

#include <iostream>

long long getNext(long long n){
	if(n%2 == 0){
		return n / 2;
	}
	return 3*n+1;
}

int main(){
	long longestNum = 0;
	long longestChain = 0;
	
	int *lengthRegister = new int[1000000];
	for(int i = 0; i < 1000000; i++){
		lengthRegister[i] = -1;
	}
	
	for(long i = 1; i < 1000000; i++){
		long long n = i;
		long len = 2;
		while((n = getNext(n)) != 1){
			len++;
		}
		lengthRegister[i] = len;
		if(len > longestChain) {
			longestChain = len;
			longestNum = i;
		}
	}
	std::cout << "Number: " << longestNum << "\tChainLength:" << longestChain << std::endl;
	delete[] lengthRegister;
}