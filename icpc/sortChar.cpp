#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class ch{
    public :
        string s;
        int count;
        ch(){s = "";count = 0;}
        bool operator>(const ch &t) const{return this->count > t.count;}
        bool operator<(const ch &t) const{return this->count < t.count;}
        bool operator==(const ch &t) const{return this->count == t.count;}

};

ostream& operator<<(ostream& os, const ch& l) {
  os << "[" << l.count << "," << l.s << "]";
  return os;
}

  string frequencySort(string s) {
        ch hash[128];
        for (int i = 0; i < 128; i++) {hash[i] = ch();}
        for (int i = 0; i < s.length(); i++) {
            hash[s[i]].count++;
            hash[s[i]].s += s[i];
        }
        vector<ch> h(hash, hash + 128);
        std::sort(h.begin(), h.end());
        int i = 127;
        string result;
        while(h[i].count != 0) {
            result += h[i].s;
            i--;
        }
        return result;
    }

int main() {
  string s;
  cin >> s;
  cout << frequencySort(s) << endl;
  return 0;
}
