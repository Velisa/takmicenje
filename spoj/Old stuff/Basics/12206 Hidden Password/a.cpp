#include <iostream>
#include <cstring>

using namespace std;

int
main(void) {
	int t;
	int numwords;
	string rijeczi, sequence;
	string delimiter = " ";
	string words[99];
	size_t pos = 0;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		//cin >> numwords;
		getline (cin, rijeczi);
		cout << i << endl;
		cout << rijeczi << endl;
		//getline (cin, sequence);
		/*
		j = 0;
		while ((pos = rijeczi.find(delimiter)) != string::npos) {
			words[j++] = rijeczi.substr (0, pos);
			rijeczi.erase (0, pos + delimiter.length());
		}
		words[j] = rijeczi;
		cout << words[0] << endl;
		cout << words[1] << endl;
		cout << words[2] << endl;
		*/
	}
	return 0;
}

