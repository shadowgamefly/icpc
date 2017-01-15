//fix
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll unsigned long long

using namespace std;

ostream& operator<<(ostream& os,vector<ll> &v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    os << v[i];
  }
  return os;
}


int main() {
  int num;
  cin >> num;
  for (int c = 1; c < num + 1; c++) {
    int balls, heights;
    cin >> balls >> heights;
    vector<ll> icecream;
    ll size;
    for (int j = 0; j < balls;j++) {
      cin >> size;
      icecream.push_back(size);
    }
//    cout << icecream << endl;
    unordered_map<int, bool> taken;
    for(int i = 0; i < balls; i++) {
      taken[i] = false;
    }

    int count = 0;
    for(;;) {
      ll cur = 1;
      for(int i = 0; i < heights; i++) {
        for(int j = 0; j < balls; j++) {
          if (icecream[j] >= cur && taken[j] == false) {
            taken[j] = true;
            cur = 2 * icecream[j];
            break;
          }
          if (j == balls - 1) goto end;
        }
      }
      count++;
    }
end:
  cout << count << endl;
  }

  return 0;
}
