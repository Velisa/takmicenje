/* STRHH - Half of the half
Given a sequence of 2*k characters, please print every second character
from the first half of the sequence. Start printing with the first
character.

Input
=====
In the first line of input your are given the positive integer t
(1<=t<=100) - the number of test cases. In the each of the next t
lines, you are given a sequence of 2*k (1<=k<=100) characters.

Output
======
For each of the test cases please please print every second character
from the first half of a given sequence (the first character should
appear).

Example
=======
Input:
4
your 
progress 
is 
noticeable

Output:
y
po
i
ntc

*/

#include <iostream>
#include <string>

using namespace std;

int 
main(void) {
	int t, i=0;
	cin >> t;
	string rijeci[t];
	for (int i=0; i < t; ++i)
		cin >> rijeci[i];
	cout << endl;
	for (int i=0; i < t; ++i) {
		for (int j = 0; j < (rijeci[i].length())/2; j+=2)
			cout << rijeci[i][j];
		cout << endl;
	}
	return 0;
}