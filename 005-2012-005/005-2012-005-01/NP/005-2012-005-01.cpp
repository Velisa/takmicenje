/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int tacke[3][2];
  //     Ax             Ay
  cin >> tacke[0][0] >> tacke[0][1];
  //     Bx             By
  cin >> tacke[1][0] >> tacke[1][1];
  //     Cx             Cy
  cin >> tacke[2][0] >> tacke[2][1];
  int a, b, c, o, p, s;
  //           Ax            Bx
  a = sqrt(pow(tacke[0][0] - tacke[1][0], 2) +
           //           Ay            By
           pow(tacke[0][1] - tacke[1][1], 2));
  //           Bx            Cx
  b = sqrt(pow(tacke[1][0] - tacke[2][0], 2) +
           //           By            Cy
           pow(tacke[1][1] - tacke[2][1], 2));
  //           Cx            Ax
  c = sqrt(pow(tacke[2][0] - tacke[0][0], 2) +
           //           Cy            Ay
           pow(tacke[2][1] - tacke[0][1], 2));
  o = a + b + c;
  s = o / 2;
  cout << "O = " << o << endl;
  cout << "P = " << sqrt(s * (s - a) * (s - b) * (s - c));
  return EXIT_SUCCESS;
}