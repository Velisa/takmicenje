#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  float x, y, z, q;
  int vrijemePolijetanja;
  int vrijemePrizemljenja;
  int satPrizemljenja;
  int minutPrizemljenja;
  int sekundPrizemljenja;
  cin >> x;
  cin >> y;
  cin >> z;
  cin >> q;
  vrijemePrizemljenja = (int)x * 60 * 60 + y * 60 + z + q;
  satPrizemljenja = (int)floor(vrijemePrizemljenja / (60 * 60));
  minutPrizemljenja =
      (int)floor((vrijemePrizemljenja - satPrizemljenja * 60 * 60) / 60);
  sekundPrizemljenja = (int)vrijemePrizemljenja - satPrizemljenja * 60 * 60 -
                       minutPrizemljenja * 60;
  satPrizemljenja = satPrizemljenja % 24;
  cout << satPrizemljenja << " sati " << minutPrizemljenja << " min "
       << sekundPrizemljenja << " sek";
  return EXIT_SUCCESS;
}