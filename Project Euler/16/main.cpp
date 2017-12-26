#include <iostream>
#include <cstring>

#define DIGIT_COUNT 500
void printArray(int *arr, int size){
	for(int i = 0; i < size ; i++){
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

void doubleArray(int *arr, int size){
	long long carry = 0;
	for(int i = 1; i <=size; i++){
		arr[size-i] *= 2;
		arr[size-i] += carry;
		carry = arr[size - i] / 10;
		arr[size-i] %= 10;
	}
}

long sumArray(int *arr, int size){
	long sum = 0;
	for(int i = 0; i < size; i++){
		sum += arr[i];				
	}
	return sum;
}

int main(){
	int digits[DIGIT_COUNT];
	std::memset(digits, 0, sizeof(int)*DIGIT_COUNT);
	digits[DIGIT_COUNT - 1] = 2;
	for(int i = 0; i < 1000 - 1; i++){
		doubleArray(digits, DIGIT_COUNT);
	}
	printArray(digits, DIGIT_COUNT);
	std::cout << sumArray(digits, DIGIT_COUNT) << std::endl;
}





















































