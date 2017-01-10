#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ca {
  public:
    vector<int> left;
    vector<int> right;
    int num;
    bool even;
    ca(string left, string right, string even) {
      if (even == "down") {string temp = left; left = right; right = temp;}
      this->even = (even == "even");
      for (int i = 0; i < left.length(); i++) {
        this->left.push_back(left[i]);
        this->right.push_back(right[i]);
      }
      num = left.size();
    }
    ca(){}
};

ostream& operator<<(ostream& os, const ca& c){
    os << c.num << " ";
    for (int i = 0; i < c.num ; i++) {
      os << c.left[i] << " " ;
    }
    os << endl;
    for (int i = 0; i < c.num ; i++) {
      os << c.right[i] << " " ;
    }
    os << endl;
    os << ((c.even)? "even" : "up");
    return os;
}

bool contain(vector<int> vec, char coin) {
  return (find(vec.begin(), vec.end(), (int)coin) != vec.end());
}

int test(ca testcase, char coin, bool heavy) { // TO FIX
  if (contain(testcase.left, coin)) return (heavy && (!testcase.even));
  else if (contain(testcase.right, coin)) return ((!heavy) && (!testcase.even));
  else return 2;
}

int uni(int a, int b, int c) {
  if (a == 0 || b == 0 || c == 0) return 0;
  if (a == 2 || b == 2
   )
}

int main() {
  int num;
  cin >> num;
  ca testcase[3] = {};
  for (int i = 0 ; i < num; i++) {
      for (int j = 0; j < 3; j++) {
        string left, right, even;
        cin >> left >> right >> even;
        testcase[j] = ca(left, right, even);
      }
      for (int i = 'A'; i < 'L'; i++) {
        bool heavy = true;
        bool pass = true;
        for (int j = 0; j < 3; j++) {
          pass = pass && test(testcase[j], char(i), heavy);
        }
        if (pass) cout << char(i) << " is the counterfeit coin and it is heavy." << endl;
      }

      for (int i = 'A'; i < 'L'; i++) {
        bool heavy = false;
        bool pass = true;
        for (int j = 0; j < 3; j++) {
          pass = pass && test(testcase[j], char(i), heavy);
        }
        if (pass) cout << char(i) << " is the counterfeit coin and it is light." << endl;
      }

  }
  return 0;
}
