/* CPTTRN1 - Character Patterns (Act 1)
Using two characters: . (dot) and * (asterisk) print a
chessboard-like pattern. The first character printed should be *
(asterisk).

Input
=====
You are given t < 100 - the number of test cases and for each of the
test cases two positive integers: l - the number of lines and c - the
number of columns in the pattern (l, c < 100).

Output
======
For each of the test cases output the requested pattern (please have
a look at the example). Use one line break in between successive
patterns.

Example
=======
Input:
3
3 1
4 4
2 5

Output:
*
.
*

*.*.
.*.*
*.*.
.*.*

*.*.*
.*.*.

*/

#include <iostream>
#include <string>

using namespace std;

int 
main(void) {
	int t, i=-1;
	cin >> t;
	int tests[t][2];
	while (t--) {
		cin >> tests[++i][0];
		cin >> tests[i][1];
	}
	cout << endl;
	for (int j = 0; j <= i; ++j) {
		for (int r = 0; r < tests[j][0]; ++r) {
			for (int s = 0; s < tests[j][1]; ++s) {
				if ((r + s) % 2 == 0) cout << "*";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}