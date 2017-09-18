#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

vector<string> getBitStrings(unsigned int n) {
    vector<string> result;
    if (n <= 1) {
        result.push_back("0");
        result.push_back("1");
    }
    else {
        vector<string> sub = getBitStrings(n-1);
        for (vector<string>::const_iterator it = sub.cbegin();
             it != sub.cend(); ++it) {
            result.push_back(*it+'0');
            result.push_back(*it+'1');
        }
    }
    return result;
}

bool jeUpitnik(char c) {
	return c=='?';	
}

bool jeSamoglasnik(char c) {
	// Pazi ovdje je 0 definisana kao genericki samoglasnik
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='0';
}

bool zadovoljava(char *rijec, int n, int k) {
	int sagl=0;
	int sugl=0;
	for (int i=0; i<n; ++i) {
		if (jeSamoglasnik(rijec[i]))
			++sagl;
		else
			++sugl;
	}
	return abs(sagl-sugl)<=k;
}

int main() {
	int n,k;
	int upit=0;
	unsigned long int ukupno = 0;
	unsigned long int kombinacije;
	unsigned long int djelilac = 1000000007;
	cin >> n >> k;
	char *rijec = new char[n+1];
	//cin.ignore();
	//cin.getline(rijec,n+1);
	cin >> rijec;
	for (int i=0; i<n; ++i) {
		if (jeUpitnik(rijec[i]))
			++upit;
	}
	//Rucno generisane samoglasnik/suglasnik kombinacije za prvobitno testiranje
	//string binarni[]={"0","1"};
	//string binarni[]={"00","01","10","11"};
	//string binarni[]={"000","001","010","011","100","101","110","111"};
	vector<string> binarni = getBitStrings(upit);
	int m;
	char *pomocna = new char[n+1];
	for (int i=0; i<pow(2,upit); ++i) {
		m = 0;
		kombinacije = 1;
		for (int j=0; j<n; ++j) {
			if (jeUpitnik(rijec[j])) {
				pomocna[j]=binarni[i][m];
				++m;
			}
			else {
				pomocna[j]=rijec[j];		
			}
		}	
		pomocna[n]='\0';
		if (zadovoljava(pomocna,n,k)) {	
			//cout << pomocna << endl;
			kombinacije = 1;
			for (int i=0; i<n; ++i) {
				if (pomocna[i]=='0') {
					kombinacije*=5;
				}
				else if (pomocna[i]=='1') {
					kombinacije*=21;
				}
				if (kombinacije > djelilac) {
					kombinacije = kombinacije % djelilac;
				}
			}
			ukupno+=kombinacije;
			if (ukupno > djelilac) {
				ukupno = ukupno % djelilac;
			}
		}
	}
	cout << ukupno << endl;
}
