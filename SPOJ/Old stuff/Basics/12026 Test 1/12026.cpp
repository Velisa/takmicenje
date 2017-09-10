/* TESTINT - Test 1
Given two natural numbers (both not greater than 200), 
each number in the separate line, please print the sum of them.

Input:
2
3

Output:
5

*/

#include <cstdio>

using namespace std;

int 
main(void) {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("\n%d\n", a+b);
	return 0;
}