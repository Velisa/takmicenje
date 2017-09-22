/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

// Za zadate test primjere, int tipovi su dovoljni
//
#include <iostream>
using namespace std;
typedef unsigned int uint;

int manjiOd(int i1,int i2) {
	return (i1 > i2 ? i2 : i1);
}

int veciOd(int i1,int i2) {
	return (i1 > i2 ? i1 : i2);
}

int main() {
	int x1, x2, x3, y1, y2, y3;
	// Unos svih koordinata
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// Ako su tacke u jednoj liniji, horizontalnoj ili vertikalnoj
	if ((x1==x2 && x2==x3) || (y1==y2 && y2==y3)) {
		cout << 1 << endl;
	}
	// Ako su dvije koordinate iste
	// (opcije za razne "L" oblike)
	else {
		int slucaj1 = 0;
		int slucaj2 = 0;
		if (x1==x2) slucaj1 = 1;
		if (x2==x3) slucaj1 = 2;
		if (x1==x3) slucaj1 = 3;
		if (y1==y2) slucaj2 = 1;
		if (y2==y3) slucaj2 = 2;
		if (y1==y3) slucaj2 = 3;
		if (slucaj1>0 && slucaj2>0) {
			cout << 2 << endl;
			return 0;
		}
		// Testovi za slucaj1
		if (slucaj1==1 && (y3>=veciOd(y1,y2) || y3<=manjiOd(y1,y2))) {
			cout << 2 << endl;
			return 0;
		}
		if (slucaj1==2 && (y1>=veciOd(y2,y3) || y1<=manjiOd(y2,y3))) {
			cout << 2 << endl;
			return 0;
		}
		if (slucaj1==3 && (y2>=veciOd(y1,y3) || y2<=manjiOd(y1,y3))) {
			cout << 2 << endl;
			return 0;
		}
		// Testovi za slucaj2
		if (slucaj2==1 && (x3>=veciOd(x1,x2) || x3<=manjiOd(x1,x2))) {
			cout << 2 << endl;
			return 0;
		}
		if (slucaj2==2 && (x1>=veciOd(x2,x3) || x1<=manjiOd(x2,x3))) {
			cout << 2 << endl;
			return 0;
		}
		if (slucaj2==3 && (x2>=veciOd(x1,x3) || x2<=manjiOd(x1,x3))) {
			cout << 2 << endl;
			return 0;
		}
		// Kada nema zajednickih koordinata
		cout << 3 << endl;
	}
}
