#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l, r;
  int lsum = 0;
  int rsum = 0;
  int dif[n];
  for (int i = 0; i < n ; i++) {
    cin >> l >> r;
    dif[i] = l - r;
    lsum += l;
    rsum += r;
  }

  int p = -1;
  int diff = lsum - rsum;
  int max = abs(diff);
  for (int i = 0 ; i < n; i++) {
    if (max < abs(diff - 2 * dif[i])) {
      max = abs(diff - 2 * dif[i]);
      p = i;
    }
  }
  cout << p + 1 << endl;
}
