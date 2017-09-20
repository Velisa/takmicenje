/* Copyright (c) Novak Petrovic
   Released under GNU General Public Licence v3.0

Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or
5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum 
of all the multiples of 3 or 5 below 1000. 

Answer: 233168 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;

int solve() {	
	const int N=1000;
	long sum=0;
	for (int i=1; i<N; ++i)
		if (i%3==0 || i%5==0) sum+=i;
	return sum;
}

TEST_CASE("Main test","[main]") {
	REQUIRE(solve()==233168);
}

//int main() {
//	cout << solve();
//}
