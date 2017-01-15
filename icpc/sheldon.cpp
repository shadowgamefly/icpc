#include <iostream>
#include <vector>
#include <string>
#define ll unsigned long long

using namespace std;
string toBinary(ll l) {
  string str(64, '0');
    for(int i = 0; i < 64; i++)
    {
        if( (1ll << i) & l)
            str[63-i] = '1';
    }
    for (int i = 0;;) {
      if (str[i] == '0') str.erase(str.begin());
      else {break;}
    }
    return str;
}

bool possible(string str) {
  int length = str.length();
//  cout << "length " << length << endl;
  int i = 0;
  int A = 0;
  int B = 0;
  while(str[i] == '1'){A++; i++;if (i == length) return true;}
  while(str[i] == '0'){B++; i++;if (i == length) return true;}
  bool poss = true;
  int cur = 0;
//  cout << A << " " << B << endl;
  while(i < length){
    for (int j = i; j < A + i; j++) {
      poss = poss && (str[j] == '1');
      if(!poss) return false;
      if(j == (length - 1) && j != (A + i - 1)) return false;
    }
    i = i + A;
    if (i == length) return true;
    for (int j = i; j < B + i; j++) {
      poss = poss && (str[j] == '0');
      if(!poss) return false;
      if(j == (length - 1) && j != (B + i - 1)) return false;
    }
    i = i + B;
  }
  return true;
}

int main() {
  ll low;
   ll high;
  cin >> low >> high;
  ll i = 0;
  ll count = 0;
  for (i = low; i <= high; i++) {
    if (i == 0) continue;
    string s = toBinary(i);
    if (possible(s)) {
      count++;
  //    cout << s << " is true"<< endl;
    }
  }

  cout << count << endl;

  return 0;

}
