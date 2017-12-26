/*
	Solution to "Problem 13 - Large Sum" from projecteuler.net/archives
	
	Solved by Velisa Petricevic
*/

#include <fstream>
#include <iostream>
#include <Math.h>

#define NUM_COUNT 100

int main(int argc, char** argv) {
	char numbers[NUM_COUNT][51];
	//Load the number
	std::ifstream stream;
	stream.open("bignumbers.txt");//Contains the required one-hundred 50-digit numbers separated by newline character. Get the numbers at projecteuler.net/problem=13
	for(int i = 0; i < NUM_COUNT || !stream.eof(); i++){
		stream >> numbers[i];
	}	
	int digits[60];
	for(int i = 0; i < 60; i++){
		digits[i] = -1;
	}
	int carry = 0;
	for(int i = 1; i < 51; i++){
		int sum = carry;
		for(int j = 0; j < NUM_COUNT; j++){
			sum += numbers[j][50 - i] - 48;
		}
		digits[60 - i] = sum % 10;
		carry = sum / 10.0;
	}
	std::cout << "Entire number: " << carry;
	for(int i = 0; i < 60; i++){
		int d = digits[i];
		if(d>-1)
		std::cout << d;
	}
	std::cout << std::endl;
	return 0;
}
