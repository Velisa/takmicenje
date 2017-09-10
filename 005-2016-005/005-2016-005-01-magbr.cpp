/* Copyright (c) Novak Petrovic GNU General Public License v3.0 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
	int N = 1000;
	char unesen_broj[N];
	//
	cin.getline(unesen_broj, N+1);
	//
	string broj = "";
	//
	int i = 0;
	bool magican = true;
	while (unesen_broj[i] != '\0') {
		broj = broj + unesen_broj[i];
		if (atoi(broj.c_str()) % (i+1) != 0) {
			magican = false;
		}
		i++;
	}
	//
	if (magican == true) {
		cout << "Broj je magican!" << endl;
	}
	else {
		cout << "Broj nije magican!" << endl;
	}
}