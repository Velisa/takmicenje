/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 200
char ulaz[MAX];
int NOP;

void brojNOP() {
  int N = strlen(ulaz);
  int NOP = 0;
  for (int i = 0; i < N; ++i) {
    if (!isupper(ulaz[i])) continue;
    while ((i + NOP) % 4 != 0) ++NOP;
  }
  cout << NOP << endl;
}

// OPCIONALNO
// Ova funkcija pise novi program
void noviProgram() {
  char izlaz[MAX + NOP];
  for (int i = 0; i < MAX + NOP; ++i) izlaz[i] = 'x';
  int nop = 0;
  int malih = 0;
  int N = strlen(ulaz);
  izlaz[0] = ulaz[0];
  for (int i = 1; i < N; ++i) {
    if (islower(ulaz[i])) {
      ++malih;
      izlaz[i + nop] = ulaz[i];
    } else {
      if ((malih + 1) % 4 == 0) {
        nop += 0;
      }
      if ((malih + 2) % 4 == 0) {
        izlaz[i + nop] = 'X';
        nop += 1;
      }
      if ((malih + 3) % 4 == 0) {
        izlaz[i + nop] = 'X';
        izlaz[i + nop + 1] = 'X';
        nop += 2;
      }
      if ((malih + 4) % 4 == 0) {
        izlaz[i + nop] = 'X';
        izlaz[i + nop + 1] = 'X';
        izlaz[i + nop + 2] = 'X';
        nop += 3;
      }
      izlaz[i + nop] = ulaz[i];
      malih = 0;
    }
  }
  cout << "Novi program je: ";
  for (int i = 0; i < MAX + NOP; ++i)
    if (izlaz[i] != 'x') cout << izlaz[i];
  cout << endl;
}

int main(void) {
  for (int i = 0; i < MAX; ++i) ulaz[i] == 'x';
  cin >> ulaz;
  brojNOP();
  // noviProgram();
  return 0;
}