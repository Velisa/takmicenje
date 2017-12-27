/*
	Solution to "Problem 9 - Special Pythagorean Triplet"
	
	Solved by Velisa Petricevic
*/

#include <iostream>
#include <Math.h>

bool isPyth(int a, int b){
	double res = sqrt(a*a+b*b);
	return (res == floor(res));
}

int main(int argc, char** argv) {
	for(int b = 1; b < 500; b++){
		int a = (500000 - b * 1000)/(1000-b);
		if(isPyth(a,b)&& a > 0 && b > 0){
			int c = int(sqrt(a*a+b*b));
			std::cout << "A is: " << a << ";B is: " << b << ";C is: " << c << "; Product is: " << a*b*c << std::endl;
			break;
		}
	}
	return 0;
}
