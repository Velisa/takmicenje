#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main (void) {
  float broj = 14.5;
  cout << fixed << setprecision(2) << round(broj*100)/100;
  return 0;
}