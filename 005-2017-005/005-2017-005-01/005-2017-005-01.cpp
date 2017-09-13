#include <iostream>

using namepsace std;

void main() {
  double x1, y1, r1, x2, y2, r2, d;
  cout << "Unesite x koordinatu centra prvog kruga: ";
  cin >> x1;
  cout << "Unesite y koordinatu centra prvog kruga: ";
  cin >> y1;
  cout << "Unesite poluprecnik prvog kruga: ";
  cin >> r1;
  cout << "Unesite x koordinatu centra drugog kruga: ";
  cin >> x2;
  cout << "Unesite y koordinatu centra drugog kruga: ";
  cin >> y2;
  cout << "Unesite poluprecnik drugog kruga: ";
  cin >> r2;
  d = sqrt((y2-y1)^2 + (x2-x1)^2);
  if (d < r1+r2) then {
    cout << "Krugovi se preklapaju";
  }
  else if (d > r1+r2) {
    cout << "Krugovi se ne preklapaju";
  }
  else {
    cout << "Krugovi se dodiruju";
  }
} 