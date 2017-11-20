/* Copyright (c) Novak Petrovic
 * Released under GNU General Public License v3.0 */

#include <math.h>
#include <iostream>
using namespace std;

int main() {
  float x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  if (d == r1 + r2)
    cout << "Krugovi se dodiruju" << endl;
  else if (d < r1 + r2)
    cout << "Krugovi se preklapaju" << endl;
  else
    cout << "Krugovi se ne preklapaju" << endl;
}
