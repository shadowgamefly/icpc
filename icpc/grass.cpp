#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
int main(){
  string line;
  cin >> line;
  int dis = 0;
  int temp = 0;
  int l = line.length();
  bool begin = true;
  char sets[] = { 'A', 'E', 'I', 'O', 'U', 'Y'};
  set<char> vol(sets, sets + 6);
  for (int i = 0; i < l; i++) {
    if (vol.find(line[i]) != vol.end()) {
      if (begin) {
        dis = i + 1;
        begin = false;
      }
      else {
        dis = max(dis, i - temp);
      }
      temp = i;
    }
  }
  dis = max(dis, l - temp);
  if (begin) dis = l + 1;
  cout << dis << endl;
  return 0;
}
