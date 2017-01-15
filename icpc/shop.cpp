#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long num;
  cin >> num;
  vector<long> price;
  int p;

  for (long i = 0; i < num ; i++) {
    cin >> p;
    price.push_back(p);
  }

  sort(price.rbegin(), price.rend());

  long out = 0;
  if (num < 3) cout << 0 << endl;
  else {
    long pos = 2;
    while (pos < num) {
      out += price[pos];
      pos += 3;
    }
    cout << out << endl;
  }

}
