#include <iostream>
#include <vector>
using namespace std;

struct jew{
  int size, val;
  jew(){};
  jew(int x, int y){ size = x; val = y;}
};

istream& operator>>(istream& is, jew& j) {
  is >> j.size >> j.val;
  return is;
}

ostream& operator<<(ostream& os, jew& j) {
  os << j.size << " " <<  j.val << endl;
  return os;
}

int main() {
    int n, size;
    while(cin >> n >> size) {
      jew j;
      vector<jew> sets;
      for (int i = 0; i < n ; i++) {cin >> j; sets.push_back(j);}
      long table[n + 1][size + 1];
      for (int j = 0; j < size + 1; j++) table[0][j] = 0;
      for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < size + 1; j++) {
          table[i][j] = sets[i].size > j ? table[i - 1][j] : max(table[i-1][j], table[i-1][j-sets[i].size] + sets[i].val);
        }
      }
      for (int i = 1; i < size + 1; i++) {
        cout << table[n][i] << " ";
      }
      cout << endl;
    }
}
