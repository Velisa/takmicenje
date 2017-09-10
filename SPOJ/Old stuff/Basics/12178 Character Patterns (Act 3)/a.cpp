#include <iostream>
using namespace std;
int
main(void) {
	int t;
	cin >> t;
	int dims[t][2];
	for (int i=0; i < t; ++i) {
		cin >> dims[i][0];
		cin >> dims[i][1];
	}
	cout << endl;
	for (int i=0; i < t; ++i) {
		for (int j=0; j < dims[i][0]*3+1; ++j) {
			for (int k=0; k < dims[i][1]*3+1; ++k)
				if (k == 0 || 
					k == (dims[i][1]*3+1)-1 || 
					j == 0 || 
					j == (dims[i][0]*3+1)-1) cout << "*";
				else 
					if (k % 3 == 0) cout << "*";
					else
						if (j % 3 == 0) cout << "*";
						else cout << ".";
			cout << endl;
		}
		cout << endl;
	}		
	return 0;
}

/*
Input:
3
3 1
4 4
2 5

Output:
*
*
*

****
*..*
*..*
****


*****
*****

*/