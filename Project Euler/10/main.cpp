/*
	Solution to "Problem 10 - Summation of primes"
	
	Solved by Velisa Petricevic
*/

#include <iostream>
#include <Math.h>

bool isPrime(long l){
	if(l < 2) return false;
	if(l == 2) return true;
	if(l%2 == 0) return false;
	for(int i = 3; i <= sqrt(l) + 1; i+= 2){
		if(l%i == 0) return false;
	}
	return true;
}

int main(int argc, char** argv) {
	unsigned long long sum = 0;
	for(long i = 0; i < 2000000; i++){
		if(isPrime(i)) { 
			sum += i;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
