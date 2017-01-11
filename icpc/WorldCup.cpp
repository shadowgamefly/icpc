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

//a, b, c, d four teams
//a vs b, a vs c , a vs d, b vs c, b vs d, c vs d
int main() {
  vector<string> cas;
  unordered_map<int, int> outcome;
  for (int i = 0; i < 729; i++) {
    string result = cast(i);
    vector<int> score;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    if (result[0] == '0') {b += 3;}
    else if (result[0] == '1') {a +=1 ; b+= 1;}
    else {a+=3;}
    if (result[1] == '0') {c += 3;}
    else if (result[0] == '1') {a +=1 ; c+= 1;}
    else {a+=3;}
    if (result[2] == '0') {d += 3;}
    else if (result[0] == '1') {a +=1 ; d+= 1;}
    else {a+=3;}
    if (result[3] == '0') {c += 3;}
    else if (result[0] == '1') {c +=1 ; b+= 1;}
    else {b+=3;}
    if (result[4] == '0') {d += 3;}
    else if (result[0] == '1') {d +=1 ; b+= 1;}
    else {b+=3;}
    if (result[5] == '0') {d += 3;}
    else if (result[0] == '1') {c +=1 ; d+= 1;}
    else {c+=3;}
    score.push_back(a);
    score.push_back(b);
    score.push_back(c);
    score.push_back(d);
    sort(score.begin(), score.begin() + 4);
    int s = score[3] * 1000 + score[2] * 100 + score[1] * 10 + score[0];
  //  cout << s << endl;
    if (outcome.find(s) == outcome.end()) {
      outcome[s] = 1;
    }
    else {
      outcome[s] ++;
    }
  }

  unordered_map<int, int>::iterator it;
  for (it = outcome.begin(); it != outcome.end(); it++) {
    cout << it->first << " " <<  it-> second <<  endl;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n ; i++) {
    int a;
    vector<int> score;
    score.clear();
    for (int j = 0; j < 4 ; j++) {
        cin >> a;
        score.push_back(a);
    }
    sort(score.begin(), score.begin() + 4);
    int s = score[3] * 1000 + score[2] * 100 + score[1] * 10 + score[0];
    cout << s << endl;
    if (outcome.find(s) == outcome.end()) {
      cout << "Case #" << i + 1 << ": Wrong Scoreboard" << endl;
    }
    else if (outcome[s] > 24) {
      cout << "Case #" << i + 1 << ": No" << endl;
    }
    else {
      cout << "Case #" << i + 1 << ": Yes" << endl;
    }
  }


}
