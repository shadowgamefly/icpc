#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int members, songs;
  cin >> members >> songs;
  vector<int> rank(songs + 1, 0);
  vector< vector<int> > pref(members, vector<int>());
  for (int i = 0; i < members; i++) {
    for (int j = 0; j < songs; j++) {
      int s;
      cin >> s;
      if (rank[s] < j) rank[s] = j;
      pref[i].push_back(s);
    }
  }
/*
  for (int i = 0; i < members; i++) {
    for (int j = 0; j < songs; j++) {
      cout << pref[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 1; i < songs + 1; i++) {
    cout << rank[i] << endl;
  }
  */
  int Toplay = 1;
  for(;;) {
    bool out = true;
    for (int i = 0; i < Toplay; i++) {
      if (rank[pref[0][i]] >= Toplay) {Toplay = rank[pref[0][i]] + 1; out = false;}
    }
    if (out) break;
  }

  vector<int> output;
  for (int i = 0; i < Toplay ; i++) {
    output.push_back(pref[0][i]);
  }

  sort(output.begin(), output.end());

  cout << Toplay << endl;
  for (int i = 0; i < Toplay ; i++) {
    cout << output[i] << " ";
  }
  cout << endl;
  return 0 ;
}
