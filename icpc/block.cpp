#include <iostream>
#include <vector>
#define ll long long
using namespace std;

bool end(ll a, ll b) {
  bool out =  (a > 2 * b) || (a % b == 0);
  return out;
}
int main() {
  ll a, b;
  cin >> a >> b;
  if (a < b) {
    ll temp = b;
    b = a;
    a = temp;
  }

  bool w = true;
  while (!end(a, b)) {
    ll temp = b;
    b = a - b;
    a = temp;
    w = !w;
  }
  cout << (w ? "win" : "lose") << endl;
}
