#include <math.h>
#include <iostream>
using namespace std;

int main() {
  long n;
  cin >> n;
  long o = n % 12;
  long c = n / 12;
  long result;
  if (o == 0)
    result = c;
  else
    result = floor(c + 1);
  cout << result;
}
