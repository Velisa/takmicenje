/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main(void) {
  string tekst;
  getline(cin, tekst);
  for (int i = 0; i < tekst.length(); ++i) {
    switch (tekst[i]) {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        break;
      default:
        cout << tekst[i];
        break;
    }
  }
  return EXIT_SUCCESS;
}