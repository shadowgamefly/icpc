#include <iostream>
#include <string>
#include <vector>

int main(){
  string s;
  cin << s;
  vector<char> seq;

  int num = seq.size();
  for (int i = 0; i < num; i++) {
    seq.push_back(seq[i]);
  }

  int counts[num + 1];
  int positions[num + 1];

  //base case
  counts[1] = 0;
  positions[1] = seq[0] == '1' ? 

}
