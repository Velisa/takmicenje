#include <iostream>
#include <math.h>

bool isPrime(long long n){
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(long long i = 3; i < sqrt(n) + 1; i+=2){
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(){
	int count = 1;
	for(long long i = 3; true; i+=2){
		if(isPrime(i)){
			count++;
			std::cout << count << ":" << i << std::endl;
		}
		if(count == 10001){
			break;
		}
	}
}
