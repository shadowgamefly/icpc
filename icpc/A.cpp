#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b, c ,d;
  while (cin >> a >> b >> c >> d) {
    if (a == -1 && b == -1) return;
    if (!(a + 1)) a = ((d - c) == (c - b)) ? (b + c - d) : (b * c / d);
    if (!(b + 1)) b = (2*(d - c) == (c - a)) ? (a + d - c) : (a * d / c);
    if (!(c + 1)) c = (2*(b - a) == (d - b)) ? (a + d - b) : (a * d / b);
    if (!(d + 1)) d = ((b - a) == (c - b)) ? (b + c - a) : (b * c / a);
    if (b * c - a * d == 0) cout << a << b << c << d;
    if ()
  }


}
