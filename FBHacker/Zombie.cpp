#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
double adb(int a, int b, int h);
class roll{
  public:
    int dice;
    int add;
    int num;
    int health;
    double prob;
    roll(int num, int dice, int add, int health) {
      this->num = num;
      this->dice = dice;
      this->add = add;
      this->health = health;
      this->prob = add >= health ? 1.0 : adb(num, dice, health - add);
    }

    bool operator<(const roll& other) const {
      return prob < other.prob;
    }
};

ostream& operator<<(ostream& os, const vector<roll>& vec){
  int n = vec.size();
  for (int i = 0; i < n; i++) {
    os << vec[i].prob << " ";
  }
  return os;
}

double probability(int a, int b, int h) {
    double dp[a+1][h+1];
    for (int i = 0; i < a+1; i++) {
        for (int j = 0; j < h+1; j++) {
            dp[i][j] = 0.0;
        }
    }

    for (int i = 1; i <= h && i <= b; i++)
        dp[1][i] = 1.0/b;


    for (int i = 2; i <= a; i++) {
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= b; k++) {
                if (j - k >= 0)
                    dp[i][j] += (1.0/b) * dp[i-1][j-k];
            }
        }
    }
    return dp[a][h];
}

double adb(int a, int b, int h) {
    double total = 0.0;
    for (int i = h; i <= a * b; i++)
        total += probability(a, b, i);
    return total;
}

int main() {
  int fight;
  cin >> fight;
  for (int n = 1; n < fight + 1; n++) {
    int total = 1;
    int success = 0;
    int health, spell;
    vector<roll> rolls;
    cin >> health >> spell;
    for (int i = 0; i < spell; i++) {
      string s;
      cin >> s;
      int t = stoi(s.substr(0, s.find("d")));
      string re = s.substr(s.find("d") + 1, -1);
//      cout << re << endl;
      if (re.find("+") == string::npos && re.find("-") == string::npos) {
        int add = 0;
        int dice = stoi(re);
        roll r = roll(t, dice, add, health);
        rolls.push_back(r);
      }
      else if (re.find("+") != string::npos) {
        int dice = stoi(re.substr(0, re.find("+")));
        int add = stoi(re.substr(re.find("+") + 1, -1));
      //    cout << dice << " " << add << endl;
        roll r = roll(t, dice, add, health);
        rolls.push_back(r);
      }
      else {
        int dice = stoi(re.substr(0, re.find("-")));
        int add = -stoi(re.substr(re.find("-") + 1, -1));
    //      cout << dice << " " << add << endl;
        roll r = roll(t, dice, add, health);
        rolls.push_back(r);
      }
    }
    sort(rolls.begin(), rolls.begin() + spell);
    cout << std::fixed;
    cout << std::setprecision(6);
    cout << "Case #" << n << ": " << rolls[spell - 1].prob << endl;
  }
}
