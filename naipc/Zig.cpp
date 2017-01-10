#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int findMin(long remain, int last, long numOfLetter) {
  int cur = 'a';
  bool plausible = false;
  while (!plausible) {
    plausible = (abs(last - cur) + max(cur - 'a', 'z' - cur) + 25 * (numOfLetter - 2)) >= remain;
    if (plausible) return cur;
    cur++;
  }
  return -1;
}

int main() {
  long diff;
  cin >> diff;
  long numOfLetter = long(ceil((double)diff/25)) + 1;
//  cout << numOfLetter << endl;
  vector<int> output;
  output.push_back('a');
  numOfLetter --;
  long n = numOfLetter;
  for (int i = 0; i < n; i++) {
    if (numOfLetter == 1) break;
    int cur = output.back();
    int next = findMin(diff, cur, numOfLetter);
//    cout << (char)next << endl;
    output.push_back(next);
    diff = diff - abs(next - cur);
    numOfLetter--;
  }
  int last = output.back();
  output.push_back(last - diff >= 'a' ? (last - diff) : (last + diff) );
  for (int i = 0; i < output.size(); i++) {
    cout << char(output[i]);
  }
  cout << endl;
  return 0;
}
