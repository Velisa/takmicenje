#include <iostream>
using namespace std;

int main(void) {
  string recenica, trazena, zamjena, prije, poslije;
  string novaRecenica = "";
  getline(cin, recenica);
  cin >> trazena;
  cin >> zamjena;
  int pos = recenica.find(trazena);
  if (pos > -1) {
    prije = recenica.substr(0, pos);
    poslije = recenica.substr(pos + trazena.length(), recenica.length());
    novaRecenica = prije + zamjena + poslije;
    cout << novaRecenica;
  } else {
    cout << "U recenici ne postoji rijec koju treba mijenjati, tako da ";
    cout << "recenica glasi" << endl;
    cout << recenica;
  }
  return 0;
}
