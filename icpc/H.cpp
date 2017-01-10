#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct line{
  int x, y;
  line(){};
  line(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

ostream& operator<<(ostream& os, const line& l) {
  os << "[" << l.x << "," << l.y << "]";
  return os;
}

istream& operator>>(istream& is, line& l) {
  is >> l.x >> l.y;
  return is;
}

istream& operator>>(istream& is, vector<line>& sets) {
  line l;
  sets.clear();
  while(cin >> l) sets.push_back(l);
  is >> sets;
  return is;
}

ostream& operator << (ostream& os, const vector<line>& sets)
{
    for (auto i : sets) os << i << "\n";
    return os;
}


int main() {
  int n;
  cin >> n;
  vector<line> sets;
  cin >> sets;
  cout << sets << endl;
}
