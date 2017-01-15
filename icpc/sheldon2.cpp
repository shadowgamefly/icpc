#include <iostream>
#include <unordered_map>
#define ll unsigned long long
using namespace std;

const unordered_map<ll, bool> &generate() {
  unordered_map<ll, bool> *l = new unordered_map<ll, bool>();
  ll A = 0;
  for(int i = 1 ; i <= 64; i++) {
    A = 2 * A + 1;
    for (int j = 1; j <= 64; j++) {
      ll sheldon = 0;
      int c1 = 1;
      int c2 = 0;
      sheldon += A;
      (*l)[sheldon] = true;
  //    cout << sheldon << endl;
      bool odd = false;
      while(i * c1 + j * c2 < 65) {
        if (odd) {
          sheldon = (sheldon << i) + A;
          (*l)[sheldon] = true;
          c1++;
        }
        else {
          sheldon = sheldon << j;
          (*l)[sheldon] = true;
          c2++;
        }
//        cout << sheldon << " " << i << " " << j << endl;
        odd = !odd;
      }
    }
  }
  (*l)[1] = false;
  return *l;
}


int main() {
  ll low, high;
  cin >> low >> high;
  unordered_map<ll, bool> l = generate();
  int count = 0;
  unordered_map<ll,bool>::iterator it;
  for (it = l.begin(); it != l.end(); it++) {
    if (it->first <= high && it->first >= low) {
      count++;
//      cout << i << endl;
    }
  }
  cout << count << endl;
  return 0;
}
