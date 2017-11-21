/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <iostream>
using namespace std;

int main() {
  int N = 1000;
  char tekst[N];
  int brojOstalih = 0;
  int brojPraznina = 0;
  int brojSuglasnika = 0;
  int brojSamoglasnika = 0;
  cin.getline(tekst, sizeof(tekst));
  int i = 0;
  while (tekst[i] != '*') {
    switch (tekst[i]) {
      case ' ':
        brojPraznina++;
        break;
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
        brojSamoglasnika++;
        break;
      case 'b':
      case 'B':
      case 'c':
      case 'C':
      case 'd':
      case 'D':
      case 'f':
      case 'F':
      case 'g':
      case 'G':
      case 'h':
      case 'H':
      case 'j':
      case 'J':
      case 'k':
      case 'K':
      case 'l':
      case 'L':
      case 'm':
      case 'M':
      case 'n':
      case 'N':
      case 'p':
      case 'P':
      case 'q':
      case 'Q':
      case 'r':
      case 'R':
      case 's':
      case 'S':
      case 't':
      case 'T':
      case 'v':
      case 'V':
      case 'w':
      case 'W':
      case 'x':
      case 'X':
      case 'y':
      case 'Y':
      case 'z':
      case 'Z':
        brojSuglasnika++;
        break;
      default:
        brojOstalih++;
    }
    ++i;
  }
  cout << "Broj samoglasnika je: " << brojSamoglasnika << endl;
  cout << "Broj suglasnika je: " << brojSuglasnika << endl;
  cout << "Broj praznina je: " << brojPraznina;
  return EXIT_SUCCESS;
}
