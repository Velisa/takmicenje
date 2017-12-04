#include <iostream>
using namespace std;

int main() {
  int broj_pumpi;
  float ukupna_udaljenost, kapacitet, potrosnja;
  cin >> ukupna_udaljenost >> kapacitet >> potrosnja >> broj_pumpi;
  float totalkm[broj_pumpi];
  // Moramo uracunati i posljednji dio puta
  float udaljenosti[broj_pumpi + 1];
  float cijene[broj_pumpi];
  for (int i = 0; i < broj_pumpi; ++i) cin >> totalkm[i];
  for (int i = 0; i < broj_pumpi; ++i) cin >> cijene[i];
  udaljenosti[0] = totalkm[0];
  for (int i = 1; i < broj_pumpi; ++i) {
    udaljenosti[i] = totalkm[i] - totalkm[i - 1];
  }
  udaljenosti[broj_pumpi] = ukupna_udaljenost - totalkm[broj_pumpi - 1];
  float rezervoar = kapacitet;
  float trosak = kapacitet * 2;
  float samostalnost = rezervoar / (potrosnja / 100);
  bool neuspijeh = false;
  for (int i = 0; i < broj_pumpi; ++i) {
    rezervoar -= udaljenosti[i] * (potrosnja / 100);
    samostalnost = rezervoar / (potrosnja / 100);
    if (rezervoar <= kapacitet / 2 || udaljenosti[i + 1] >= samostalnost) {
      trosak += 5;
      trosak += (kapacitet - rezervoar) * cijene[i];
      rezervoar = kapacitet;
      samostalnost = rezervoar / (potrosnja / 100);
      if (udaljenosti[i + 1] >= samostalnost) {
        cout << "Ne moze se stici do sljedeceg odredista";
        neuspijeh = true;
        break;
      }
    }
  }
  if (!neuspijeh) {
    printf("%.1f", trosak);
  }
  return 0;
}