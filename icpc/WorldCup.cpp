#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

string cast(int p) {
  string s;
  while(p != 0) {
    int temp;
    temp = p / 3;
    s.append(to_string(p - temp * 3));
    p = temp;
  }

  if (s.size() < 7) {
    int n = s.size();
    for (int i = 0; i < 6 - n; i++) {
      s.append("0");
    }
  }
  return s;
}

int possible(int a, int b, int c, int d) {
  return (a < 10) && (a > 0) && (b < 10) && (b > 0) && (c < 10) && (c > 0) && (d < 10) && (d > 0);
}
//a, b, c, d four teams
//a vs b, a vs c , a vs d, b vs c, b vs d, c vs d
int main() {
  int output[10][10][10][10];
  for(int a = 0; a < 10; a++) {
    for(int b = 0; b < 10; b++) {
      for(int c = 0; c < 10; c++) {
        for(int d = 0; d < 10; d++) {
          output[a][b][c][d] = -1;
        }
      }
    }
  }

}
