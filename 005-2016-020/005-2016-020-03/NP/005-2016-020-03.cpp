#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x[N], y[N];
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
  int M;
  cin >> M;
  int x1[M], x2[M], y1[M], y2[M];
  for (int i = 0; i < M; ++i) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  //
  int brojac = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (
          // Borovi moraju biti u okviru setalista
          (x[j] >= x1[i] && x[j] <= x2[i] && y[j] >= y1[i] && y[j] <= y2[i]) &&
          // Borovi moraju biti na ivicama setalista
          (x[j] == x1[i] || x[j] == x2[i] || y[j] == y1[i] || y[j] == y2[i])) {
        ++brojac;
      }
    }
    cout << brojac << endl;
    brojac = 0;
  }
  return 0;
}
