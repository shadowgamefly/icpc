#include <iostream>
#include <queue>
#define ll long long
using namespace std;
int main() {
  int num;
  cin >> num;
  for (int n = 0; n < num; n++) {
    int sticks;
    cin >> sticks;
    priority_queue<ll> q;
    ll length;
    for (int i = 0; i < sticks; i++) {
      cin >> length;
      q.push(-length);
    }
    ll cost = 0;
    while(q.size() > 1) {
      ll temp = 0;
      temp += q.top();
      q.pop();
      temp += q.top();
      q.pop();
      q.push(temp);
      cost += temp;
    }
    cout << -cost << endl;
  }
}
