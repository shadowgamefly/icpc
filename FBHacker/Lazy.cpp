#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& vec){
  int n = vec.size();
  for (int i = 0; i < n; i++) {
    os << vec[i] << " ";
  }
  return os;
}


int main() {
  int days;
  cin >> days;
  for (int n = 1; n < days + 1; n++) {
    int items;
    vector<int> weights;
    cin >> items;
    for (int i = 0; i < items; i++) {
      int w;
      cin >> w;
      weights.push_back(w);
    }
    sort(weights.begin(), weights.begin() + items);
    bool con = true;
    int count = 0;
    while(con) {
      int currentTop = weights.back();
      weights.pop_back();
      int totalWeight = currentTop;
      while (totalWeight < 50) {
        totalWeight += currentTop;
        if (weights.empty()) {
          cout << "Case #" << n << ": " << count << endl;
          con = false;
          break;
        }
        weights.erase(weights.begin());
      //  cout << weights << endl;
      }
      count++;
      if (weights.empty() && con) {
        cout << "Case #" << n << ": " << count << endl;
        break;
      }
  }
}
}
