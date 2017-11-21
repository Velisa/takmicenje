/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  int jovan = 0;
  int marko = 0;
  cin >> N;
  int potezi[N];
  for (int i = 0; i < N; ++i) {
    cin >> potezi[i];
  }
  bool igraJovan = true;
  for (int i = 0; i < N; ++i) {
    if (igraJovan) {
      jovan += potezi[i];
      if (jovan == marko) {
        marko = 0;
      }
      if (potezi[i] == 6) {
        igraJovan = true;
      } else {
        igraJovan = false;
      }
    } else {
      marko += potezi[i];
      if (marko == jovan) {
        jovan = 0;
      }
      if (potezi[i] == 6) {
        igraJovan = false;
      } else {
        igraJovan = true;
      }
    }
  }
  if (igraJovan) {
    cout << "JOVAN" << endl;
  } else {
    cout << "MARKO" << endl;
  }
  cout << jovan << endl;
  cout << marko;
  return EXIT_SUCCESS;
}