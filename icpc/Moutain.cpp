#include <iostream>
#include <vector>
using namespace std;

int main() {
  int l , h, w;

  while (cin >> l >> w >> h) {
    long long table[w][l + 1];
    for (int i = 0; i < w ;i++) {
      for (int j = 0; j < l; j++) {
        table[i][j] = 0;
      }
    }
    for (int j = 0; j < l + 1 ; j++ ) {
      table[0][j] = h > j ? (j + 1): (h + 1);
    }
    for (int i = 1; i < w; i++) {
      for (int p = 0 ; p < l + 1 ; p++) {
        long long result = 0;
        for (int j = 0; j < h + 1; j++) result += ((p - j < 0) ? 0 : table[i-1][p-j]) % 1000000007;
        table[i][p] = result % 1000000007;
      }
    }
    table[w - 1][l] -= ((l / w > h) ? h : (l / w) + 1);
    cout << table[w - 1][l] << endl;
  }

}
