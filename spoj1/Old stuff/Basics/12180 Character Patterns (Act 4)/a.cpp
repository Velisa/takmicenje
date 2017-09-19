#include <iostream>
using namespace std;
int
main(void) {
	int t, rows, cols;
	cin >> t;
	int dims[t][4];
	for (int i = 0; i < t; ++i) {
		cin >> dims[i][0];
		cin >> dims[i][1];
		cin >> dims[i][2];
		cin >> dims[i][3];
	}
	cout << endl;
	for (int i = 0; i < t; ++i) {
		//     redova       tacaka po redu   razmaka izm. tacaka   okvir
		rows = dims[i][0] * dims[i][2]       + (dims[i][0] - 1)  + 2;
		cols = dims[i][1] * dims[i][3]       + (dims[i][1] - 1)  + 2;
		for (int j = 0; j < rows; ++j) {
			for (int k = 0; k < cols; ++k)
				if (k == 0 || 
					k == cols - 1 || 
					j == 0 || 
					j == rows - 1) cout << "*";
				else 
					if (j % (dims[i][2] + 1) == 0) cout << "*";
					else
						if (k % (dims[i][3] + 1) == 0) cout << "*";
						else cout << ".";
			cout << endl;
		}
		cout << endl;
	}		
	return 0;
}