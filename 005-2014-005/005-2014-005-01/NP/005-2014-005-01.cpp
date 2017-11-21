/* Copyright (c) Novak Petrovic
 * GNU General Public License v3.0
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int main(void) {
  int dan, mjesec, godina;
  int prethodniDan, prethodniMjesec, prethodnaGodina;
  int sljedeciDan, sljedeciMjesec, sljedecaGodina;
  cin >> dan;
  cin >> mjesec;
  cin >> godina;
  bool prestupna = false;
  if (godina % 4 == 0 && godina % 100 == 0 && godina % 400 == 0) {
    prestupna = true;
  }
  bool vazeci = true;
  if (godina < 1) vazeci = false;
  if (mjesec < 1 || mjesec > 12) vazeci = false;
  switch (mjesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (dan < 1 || dan > 31) vazeci = false;
      break;
    case 6:
    case 9:
    case 11:
      if (dan < 1 || dan > 30) vazeci = false;
      break;
    case 2:
      if (!prestupna && dan < 1 || dan > 28) vazeci = false;
      if (prestupna && dan < 1 || dan > 29) vazeci = false;
      break;
  }
  if (vazeci) {
    // Mozda nije najoptimalnije testirati svaki mjesec posebno,
    // ali  najbezbjednije je razmotriti svaku situaciju posebno
    switch (mjesec) {
      case 1:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 1;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 12;
          prethodnaGodina = godina - 1;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 2;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 1;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = 1;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = 1;
          prethodnaGodina = godina;
        }
        break;
      case 2:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 2;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 1;
          prethodnaGodina = godina;
        } else if (dan == 28) {
          if (prestupna) {
            sljedeciDan = 29;
            sljedeciMjesec = 2;
            sljedecaGodina = godina;
            prethodniDan = 27;
            prethodniMjesec = 2;
            prethodnaGodina = godina;
          } else {
            sljedeciDan = 1;
            sljedeciMjesec = 3;
            sljedecaGodina = godina;
            prethodniDan = 27;
            prethodniMjesec = 2;
            prethodnaGodina = godina;
          }
        } else if (dan == 29) {
          sljedeciDan = 1;
          sljedeciMjesec = 3;
          sljedecaGodina = godina;
          prethodniDan = 28;
          prethodniMjesec = 2;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 3:
        if (dan == 1) {
          if (prestupna) {
            sljedeciDan = 2;
            sljedeciMjesec = 3;
            sljedecaGodina = godina;
            prethodniDan = 29;
            prethodniMjesec = 2;
            prethodnaGodina = godina;
          } else {
            sljedeciDan = 2;
            sljedeciMjesec = 3;
            sljedecaGodina = godina;
            prethodniDan = 28;
            prethodniMjesec = 2;
            prethodnaGodina = godina;
          }
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 4;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 3;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 4:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 4;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 3;
          prethodnaGodina = godina;
        } else if (dan == 30) {
          sljedeciDan = 1;
          sljedeciMjesec = 5;
          sljedecaGodina = godina;
          prethodniDan = 29;
          prethodniMjesec = 4;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 5:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 5;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 4;
          prethodnaGodina = godina;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 6;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 5;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 6:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 6;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 5;
          prethodnaGodina = godina;
        } else if (dan == 30) {
          sljedeciDan = 1;
          sljedeciMjesec = 7;
          sljedecaGodina = godina;
          prethodniDan = 29;
          prethodniMjesec = 6;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 7:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 7;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 6;
          prethodnaGodina = godina;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 8;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 7;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 8:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 8;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 7;
          prethodnaGodina = godina;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 9;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 8;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 9:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 9;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 8;
          prethodnaGodina = godina;
        } else if (dan == 30) {
          sljedeciDan = 1;
          sljedeciMjesec = 10;
          sljedecaGodina = godina;
          prethodniDan = 29;
          prethodniMjesec = 9;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 10:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 10;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 9;
          prethodnaGodina = godina;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 11;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 10;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 11:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 11;
          sljedecaGodina = godina;
          prethodniDan = 31;
          prethodniMjesec = 10;
          prethodnaGodina = godina;
        } else if (dan == 30) {
          sljedeciDan = 1;
          sljedeciMjesec = 12;
          sljedecaGodina = godina;
          prethodniDan = 29;
          prethodniMjesec = 11;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
      case 12:
        if (dan == 1) {
          sljedeciDan = 2;
          sljedeciMjesec = 12;
          sljedecaGodina = godina;
          prethodniDan = 30;
          prethodniMjesec = 11;
          prethodnaGodina = godina;
        } else if (dan == 31) {
          sljedeciDan = 1;
          sljedeciMjesec = 1;
          sljedecaGodina = godina + 1;
          prethodniDan = 30;
          prethodniMjesec = 12;
          prethodnaGodina = godina;
        } else {
          sljedeciDan = dan + 1;
          sljedeciMjesec = mjesec;
          sljedecaGodina = godina;
          prethodniDan = dan - 1;
          prethodniMjesec = mjesec;
          prethodnaGodina = godina;
        }
        break;
    }
    cout << "Datum: " << dan << "." << mjesec << "." << godina << " Prethodni "
         << prethodniDan << "." << prethodniMjesec << "." << prethodnaGodina
         << ". Naredni " << sljedeciDan << "." << sljedeciMjesec << "."
         << sljedecaGodina << ". godine";
  } else {
    cout << "Datum: " << dan << "." << mjesec << "." << godina
         << " neispravan.";
  }
  return EXIT_SUCCESS;
}