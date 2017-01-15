#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int n = 0; n < cases; n++) {
    vector<int> h1;
    vector<int> h2;
    int keys;
    int size;
    cin >> keys >> size;
    for (int i = 0; i < keys; i++) {
      int h;
      cin >> h;
      h1.push_back(h);
      cin >> h;
      h2.push_back(h);
    }
    vector<int> dic;
    for (int i = 0; i < size; i++) {
      dic.push_back(-1);
    }
    bool success = true;
    set<int> count;
    for (int toput = 0; toput < keys ; toput++) {
      int T = toput;
      int pos = h1[toput];
      if (dic[pos] == -1) {dic[pos] = toput; continue;}
      pos = h2[toput];
      while (dic[pos] != -1) {
        int temp = dic[pos];
        dic[pos] = toput;
        toput = temp;
        if (toput == T && pos == h1[toput]) {success = false; break;}
        pos = (h1[toput] == pos) ? h2[toput] : h1[toput];
      }
      if (success == false) break;
      dic[pos] = toput;
      toput = T;
    }
    cout << (success ? "successful hashing" : "rehash necessary") << endl;
  }
}
