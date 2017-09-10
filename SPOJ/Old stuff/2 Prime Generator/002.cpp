/* PRIME1: Prime Generator
Peter wants to generate some prime numbers for his cryptosystem. Help
him! Your task is to generate all prime numbers between two given 
numbers!

Input
=====
The input begins with the number t of test cases in a single line
(t<=10). In each of the next t lines there are two numbers m and n 
(1 <= m <= n <= 1,000,000,000, n-m<=100,000) separated by a space.

Output
======
For every test case print all prime numbers p such that m <= p <= n,
one number per line, test cases separated by an empty line.
*/
#include <cstdio>
#include <iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define DIFF_SIZE 100000

using namespace std;

int myPrimes[DIFF_SIZE];
int cnt;

void 
populateMyPrimes (int N) {
	int i = 0, j = 0;
	bool primeArray[DIFF_SIZE];
	for (i = 2; i < DIFF_SIZE; ++i) {
		primeArray[i] = true;
		myPrimes[i] = 0;
	}
	int myRange = floor (sqrt ((double)N));
	int k = floor (sqrt ((double)myRange));
	for (i = 2; i <= k; ++i) {
		if (primeArray[i] == true) {
			for (j = i*i; j <= myRange; j = j + i) {
				primeArray[j] = false;
			}
		}
	}
	cnt=0;
	for (i = 2; i <= myRange; ++i) {
		if (primeArray[i] == true) {
			myPrimes[cnt++] = i;
		}
	}
}

/* First, brute-force attempt: TLE */
void
testprime(int j) {
	bool prost = true;
	for (int k = 2; k < j; ++k)
		if (j % k == 0) prost = false;
			if (prost) cout << endl << j;
}

int 
main(void) {
	int numcases, m, n, s, p=0;
	bool primesNow[DIFF_SIZE];
	scanf ("%d", &numcases);
	int testcases[numcases][2];
	for (int i = 0; i < numcases; ++i) {
		cin >> m;
		cin >> n;
		testcases[i][0] = m;
		testcases[i][1] = n;
	}
	for (int k = 0; k < numcases; ++k) {
		for (int i = 0; i < DIFF_SIZE; ++i)
			primesNow[i]=true;
		populateMyPrimes(testcases[k][1]);
		for (int i = 0; i < cnt; ++i) {
			p = myPrimes[i];
			s = testcases[k][0]/p;
			s = s*p;
			for (int j=s; j <= testcases[k][1]; j=j+p) {
				if (j < testcases[k][0]) continue;
				primesNow[j-testcases[k][0]] = false;
			}
		}
		/* In the above loop the first prime numbers for example say 2 and 3 are also set to false
		hence we need to print them in case they are within range. Without this loop you will see
		that for a range 1-30, 2 and 3 does not get printed. */
		for (int i=0; i < cnt; ++i) { 
			if(myPrimes[i] >= testcases[k][0] && myPrimes[i] <= testcases[k][1])
				cout << endl << myPrimes[i];
		}
		for (int i=0; i < testcases[k][1]-testcases[k][0]+1; ++i) {
			if (primesNow[i] == true && (i+testcases[k][0])!=1) // The condition (i+M != 1) is to ensure that for i=0 and M=1, number 1 is not printed
				cout << endl << i+testcases[k][0];
		}
		cout << endl;
	}	
	return 0;
}