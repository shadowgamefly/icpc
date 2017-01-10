#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int orderness(string str) {
  int count = 0;
  for (int i = 0; i < str.size() ; i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (str[i] > str[j]) count++;
    }
  }
  return count;
}

class DNA {
public:
  string DNAs;
  int order;
  bool operator<(const DNA& other) const {
    return order < other.order;
  }
  DNA(string s) {
    DNAs = s;
    order = orderness(s);
  }
};

int main() {
  int length = 0;
  int num = 0;
  cin >> length >> num;
  vector<DNA> series;
  for (int i = 0; i < num;i++) {
    string str;
    cin >> str;
    DNA d = DNA(str);
    series.push_back(d);
  }
  sort(series.begin(), series.begin() + num);
  for (int i = 0 ; i < num ; i++) {
    cout << series[i].DNAs << endl;
  }
  return 0;
}
