#include <iostream>
using namespace std;

int main() {
  int broj_pumpi;
  float udaljenost, kapacitet, potrosnja;
  cin >> udaljenost >> kapacitet >> potrosnja >> broj_pumpi;
  float totalkm[broj_pumpi], udaljenosti[broj_pumpi], cijene[broj_pumpi];
  for (int i = 0; i < broj_pumpi; ++i) cin >> totalkm[i];
  for (int i = 0; i < broj_pumpi; ++i) cin >> cijene[i];
  udaljenosti[0] = totalkm[0];
  for (int i = 1; i < broj_pumpi; ++i) {
    udaljenosti[i] = totalkm[i] - totalkm[i - 1];
  }
  float rezervoar = kapacitet;
  float trosak = kapacitet * 2;
  float samostalnost = rezervoar / (potrosnja / 100);

  for (int i = 0; i < broj_pumpi - 1; ++i) {
    rezervoar -= udaljenosti[i] * (potrosnja / 100);
    samostalnost = rezervoar / (potrosnja / 100);
    if (rezervoar < kapacitet / 2 || udaljenosti[i + 1] >= samostalnost) {
      trosak += 5;
      trosak += (kapacitet - rezervoar) * cijene[i];
      rezervoar = kapacitet;
    }
  }
  rezervoar -= udaljenosti[broj_pumpi - 1] * (potrosnja / 100);
  if (rezervoar <= 0) {
    cout << "Kraj puta: posljednja pumpa je predaleko" << endl;
  } else {
    printf("%.1f", trosak);
  }
  return 0;
}