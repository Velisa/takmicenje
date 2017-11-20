#include <cmath>
#include <iostream>
using namespace std;

int main() {
  float polupr;
  int takmicara, bodovi;
  cin >> takmicara;
  string pogoci[takmicara];
  for (int i = 0; i < takmicara; ++i) {
    cin >> pogoci[i];
  }
  string sx, sy;
  int zagrada, zarez;
  int pogodaka = 5;
  int x[takmicara][pogodaka], y[takmicara][pogodaka];

  for (int t = 0; t < takmicara; ++t) {
    int kraj = pogoci[t].length();
    string sub = pogoci[t].substr(0, kraj);
    int brojac = 0;
    while (true) {
      zagrada = sub.find('(');
      zarez = sub.find(',');
      sx = sub.substr(zagrada + 1, zarez);
      x[t][brojac] = stoi(sx);
      zagrada = sub.find(')');
      sy = sub.substr(zarez + 1, zagrada);
      y[t][brojac] = stoi(sy);
      if (zagrada == kraj - 1)
        break;
      else {
        sub = sub.substr(zagrada + 2, kraj);
        kraj = sub.length();
        ++brojac;
      }
    }
    bodovi = 0;
    for (int i = 0; i < pogodaka; ++i) {
      polupr = sqrt(pow(x[t][i], 2) + pow(y[t][i], 2));
      if (polupr <= 1.0)
        bodovi += 10;
      else if (polupr > 1.0 && polupr <= 2.0)
        bodovi += 9;
      else if (polupr > 2.0 && polupr <= 3.0)
        bodovi += 8;
      else if (polupr > 3.0 && polupr <= 4.0)
        bodovi += 7;
      else if (polupr > 4.0 && polupr <= 5.0)
        bodovi += 6;
      else if (polupr > 5.0 && polupr <= 6.0)
        bodovi += 5;
      else if (polupr > 6.0 && polupr <= 7.0)
        bodovi += 4;
      else if (polupr > 7.0 && polupr <= 8.0)
        bodovi += 3;
      else if (polupr > 8.0 && polupr <= 9.0)
        bodovi += 2;
      else if (polupr > 9.0 && polupr <= 10.0)
        bodovi += 1;
    }
    cout << t + 1 << ". takmicar " << bodovi << " bodova" << endl;
  }
  return 0;
}
