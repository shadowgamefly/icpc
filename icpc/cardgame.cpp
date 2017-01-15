#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream &os, vector<int> &v) {
  int size = v.size();
  for (int i = 0; i < size; i++) {
    os << v[i] << " ";
  }
  return os;
}

int main() {
  int value;
  int lines;
  int k;
  cin >> lines >> k;
  for (int l = 0; l < lines; l++) {
    vector<int> v;
    int num;
    cin >> num;
    for(int j = 0 ; j < num; j++){
      int p;
      cin >> p;
      v.push_back(p);
    }

    int max = num + 1;
    int dp[max];
    //find score of the given pile using dp;
    dp[0] = 0;
    dp[1] = (v[0] == 1);
    for(int i = 2; i < max; i++) {
      set<int> possible;
      vector<int>::iterator it = v.begin() + i;
      vector<int> now = vector<int>(v.begin(), it);
      cout << now << endl;
      for (int taken = 0; taken < k + 1; taken++) {
        vector<int> temp = now;
        if (taken > temp.size()) {possible.insert(0); continue;}
        else {
          temp.erase(temp.end() - taken, temp.end());
          int totake = temp.back();
          if (totake >= temp.size()) {possible.insert(0); continue;}
          temp.erase(temp.end() - totake, temp.end());
          possible.insert(dp[temp.size()]);
        }
      }
      vector<int> val(possible.begin(), possible.end());
//      cout << val << endl;
      sort(val.begin(), val.begin() + val.size());
      int j = 0;
      for(;;) {if(val[j] != j) break; else j++;}
      dp[i] = j;
    }
    value = value ^ dp[num];
  }
  cout << ((value == 0) ? ("Bob will win.") : ("Alice can win.")) << endl;
}
