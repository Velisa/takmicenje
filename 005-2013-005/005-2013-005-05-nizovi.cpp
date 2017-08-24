#include <iostream>
#include <math.h>

using namespace std;

int main (void) {
    int N, k;
    cin >> N;
    int niz[N];
    for (int i=0; i < N; ++i) {
        cin >> niz[i];
	}
	cin >> k;
	int noviniz[k];
    bool aritmeticki = false;
	bool geometrijski = false;
    if ((niz[0] + niz[2])/2 == niz[1]) {
        aritmeticki = true;
	}
    else if (sqrt((niz[0] * niz[2])) == niz[1]) {
		geometrijski = true;
	}
    for (int i=3; i < N ; ++i)
        if (niz[i] == 2*niz[i-1] - niz[i-2])
			continue;
        else
            aritmeticki = false;
	for (int i=3; i < N ; ++i)
        if (niz[i] == niz[i-1] * niz[i-1] / niz[i-2])
			continue;
        else
            geometrijski = false;
    if (aritmeticki && !geometrijski)
        cout << "aritmeticki";
    else if (!aritmeticki && geometrijski)
        cout << "geometrijski";
	else if (!aritmeticki && !geometrijski)
		cout << "nikakav";
    if (k <= N)
        cout << endl << niz[k-1];
    else {
		if (aritmeticki && !geometrijski) {
			noviniz[0] = niz[N-2];
			noviniz[1] = niz[N-1];
			for (int j=2; j <= k-N+1; ++j)
				noviniz[j] = 2*noviniz[j-1] - noviniz[j-2];
			cout << endl << noviniz[k-N+1];
		}
		if (!aritmeticki && geometrijski) {
			noviniz[0] = niz[N-2];
			noviniz[1] = niz[N-1];
			for (int j=2; j <= k-N+1; ++j)
				noviniz[j] = noviniz[j-1]*noviniz[j-1] / noviniz[j-2];
			cout << endl << noviniz[k-N+1];
		}
    }
    return 0;
}