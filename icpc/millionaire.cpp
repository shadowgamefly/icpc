#include <iostream>
#include <vector>
#include <queue>
#define ll long long


using namespace std;

#define MAX_LENGTH 1000
#define p(a, b) (a*10000 + b)

ll grid[MAX_LENGTH][MAX_LENGTH];

bool plausible(ll length, int width, int height) {
  bool access[height][width];
  for (int i = 0; i < height; i ++) {
    for (int j = 0; j < width ;j ++) {
      access[i][j] = false;
    }
  }

  queue<ll> q;
  q.insert(p(a,b))
  while(!list.empty()) {
    int point = list.front();
    list.pop();
    int a = point / 10000;
    int b = point % 10000;
    access[a][b] = true;
    if (a == 0 && b == 0) {
      if (!access[a+1][b]) list.push(p(a+1, b));
      if (!access[a][b+1]) list.push(p(a, b+1));
    }
    else if (a == 0 && (b == height - 1)) {
      if (!access[a+1][b]) list.push(p(a+1, b));
      if (!access[a][b-1]) list.push(p(a, b-1));
    }
    else if ((a == width - 1) && (b == 0)) {
      if (!access[a][b + 1]) list.push(p(a, b + 1));
      if (!access[a - 1][b]) list.push(p(a - 1, b));
    }
    else if ((a == width - 1) && (b == height - 1)) {
      if (!access[a][b - 1]) list.push(p(a, b - 1));
      if (!access[a-1][b]) list.push(p(a-1, b));
    }
    else if (a == 0) {
      if (!access[a][b-1]) list.push(p(a, b - 1));
      if (!access[a][b+1]) list.push(p(a, b + 1));
      if (!access[a+1][b]) list.push(p(a+1, b));
    }
    else if (b == 0) {
      if (!access[a-1][b]) list.push(p(a-1, b));
      if (!access[a+1][b]) list.push(p(a+1, b));
      if (!access[a][b+1]) list.push(p(a, b+1));
    }
    else if (a == width-1) {
      if (!access[a][b-1]) list.push(p(a, b - 1));
      if (!access[a][b+1]) list.push(p(a, b + 1));
      if (!access[a-1][b]) list.push(p(a-1, b));
    }
    else if (b == height-1) {
      if (!access[a-1][b]) list.push(p(a-1, b));
      if (!access[a+1][b]) list.push(p(a+1, b));
      if (!access[a][b-1]) list.push(p(a, b-1));
    }
    else {
      if (!access[a-1][b]) list.push(p(a-1, b));
      if (!access[a+1][b]) list.push(p(a+1, b));
      if (!access[a][b-1]) list.push(p(a, b-1));
      if (!access[a][b-1])
    }

}

int main() {
  int height, width;
  cin >> height >> width;
  for (int i = 0; i < height; i++) {
    for (int j = 0 ; j < width; j++) {
      cin >> grid[i][j];
    }
  }
/*
  for (int i = 0; i < height; i++) {
    for (int j = 0 ; j < width; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
*/
  ll high = 1000000001;
  ll low = 0;
  ll mid;
  while(high > low) {
    mid = (high + low)/2;
    if (plausible(mid)) {
      high = mid;
    }
    else {
      low = mid + 1;
    }
  }
  cout << mid << endl;
  return 0;
}
