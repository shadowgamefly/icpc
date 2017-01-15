#include <iostream>
#include <vector>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int n = 0 ; n < cases; n ++) {
    int shops;
    cin  >> shops;
    vector<int> s;
    int sh;
    for (int i = 0; i < shops ; i++){
      cin >> sh;
      s.push_back(sh);
    }
    int max = s[0];
    int min = s[0];
    for (int i = 0; i < shops ; i++){
      if (s[i] > max) max = s[i];
      if (s[i] < min) min = s[i];
    }
    cout << (max - min) * 2 << endl;
  }
  return 0;
}
