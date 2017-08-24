#include <stdio.h>
#include <iostream>

using namespace std;

int
main (void) {
	int N;
    //cout << "C++ - Unesite duzinu niza A (<=50): ";
    cin >> N;
    int A[N], suma = 0;
	float B[2*N];
    for (int i=0; i < N; ++i) {
        cin >> A[i];
		suma += A[i];
	}
	for (int i=0; i < N; i++) {
		B[2*i] = A[i];
	}
	B[1] = (float) suma/N;
	for (int i=3; i < 2*N; i+=2) {
        B[i] = B[i-2] + 1;
	}
	for (int i=0; i < 2*N; i++) {
		if (i % 2 == 0)
			printf("%.0f ", B[i]);
		else
			printf("%.2f ", B[i]);
	}
	cout << endl;
    return 0;
}