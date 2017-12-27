/*
	Solution to "Problem 12 - Highly divisible triangular number" from projecteuler.net/archives
	
	Solved by Velisa Petricevic
*/
#include <iostream>
#include <Math.h>

int countDivisors(unsigned long long num){
	int divisorCount = 2;//1 and itself
	for(int i = 2; i < sqrt(num)+1; i ++){
		if(num % i == 0) {
			divisorCount += 2;//i and 1/i
		}
	}
	return divisorCount;
}

int main(int argc, char** argv) {
	unsigned long long i = 1;
	unsigned long long n = 0;
	while(true){
		n += i;
		int cd = countDivisors(n);
		std::cout << n << "\t" << cd << std::endl; 
		if(cd > 500){
			std::cout << n << std::endl;
			break;
		}
		i++;
	}
	return 0;
}
