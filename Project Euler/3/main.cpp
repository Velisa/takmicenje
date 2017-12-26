#include <iostream>
#include <math.h>

#define LARGENUM 600851475143 

bool isPrime(long long n){
	if(n % 2 == 0) return false;
	for(int i = 3; i < sqrt(n); i+=2){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	for(long long i = 3; i < LARGENUM/3; i++){
		if(LARGENUM % i == 0){
			long long solution = LARGENUM / i;
			if(isPrime(solution)){
				std::cout << solution << std::endl;
				break;
			}
		}
	}
}