#include <iostream>
using namespace std;

int main() {
  int zaspao, zaspao_sat, zaspao_min;
  int spavao, spavao_sat, spavao_min;
  int probudiose, probudiose_dan, probudiose_sat, probudiose_min;
  string dan, probudiose_dan_str;
  cin >> dan;
  int zaspao_dan;
  if (dan == "ned") {
    zaspao_dan = 0;
  } else if (dan == "pon") {
    zaspao_dan = 1;
  } else if (dan == "uto") {
    zaspao_dan = 2;
  } else if (dan == "sre") {
    zaspao_dan = 3;
  } else if (dan == "cet") {
    zaspao_dan = 4;
  } else if (dan == "pet") {
    zaspao_dan = 5;
  } else if (dan == "sub") {
    zaspao_dan = 6;
  }
  cin >> zaspao_sat;
  cin >> zaspao_min;
  cin >> spavao_sat;
  cin >> spavao_min;
  zaspao = 60 * zaspao_sat + zaspao_min;
  probudiose = zaspao + spavao_sat * 60 + spavao_min;
  probudiose_dan = zaspao_dan + probudiose / (24 * 60);
  probudiose_dan = probudiose_dan % 7;
  probudiose_sat = (probudiose % (24 * 60)) / 60;
  probudiose_min = (probudiose % (24 * 60)) % 60;
  switch (probudiose_dan) {
    case 0:
      probudiose_dan_str = "ned";
      break;
    case 1:
      probudiose_dan_str = "pon";
      break;
    case 2:
      probudiose_dan_str = "uto";
      break;
    case 3:
      probudiose_dan_str = "sre";
      break;
    case 4:
      probudiose_dan_str = "cet";
      break;
    case 5:
      probudiose_dan_str = "pet";
      break;
    case 6:
      probudiose_dan_str = "sub";
      break;
  }
  cout << probudiose_dan_str << " " << probudiose_sat << " " << probudiose_min;
  return 0;
}
