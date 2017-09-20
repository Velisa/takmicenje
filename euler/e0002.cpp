/* Copyright (c) Novak Petrovic
   Released under GNU General Public Licence v3.0

Even Fibonacci numbers

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By startgin with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even valued terms. 

Answer: 4613732 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;

int solve() {	
	const int max=4e6;
	int first=1;
	int second=2;
	int sum=second; // Because it's even
	int third=first+second;
	while (third <= max) {
		if (third%2==0) {
			sum+=third;
		}
		first=second;
		second=third;
		third=first+second;
	}
	return sum;
}

TEST_CASE("Main test","[main]") {
	REQUIRE(solve()==4613732);
}

//int main() {
//	cout << solve();
//}