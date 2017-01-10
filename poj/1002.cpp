#include <iostream>
#include <string>
#include <map>


using namespace std;

string trans(string str) {
  for (int i = 0; i < 7; i++) {
    if (str[i] > 86) str[i] = '9';
    else if (str[i] > 83) str[i] = '8';
    else if (str[i] > 79) str[i] = '7';
    else if (str[i] > 76) str[i] = '6';
    else if (str[i] > 73) str[i] = '5';
    else if (str[i] > 70) str[i] = '4';
    else if (str[i] > 67) str[i] = '3';
    else if (str[i] > 64) str[i] = '2';
    }
  return str;
}

string turns(string str) {
  str.insert(3, "-");
  return str;
}

string del(string str) {
  string s = "";
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '-') s += str[i];
  }
  return s;
}

int main()
{
    int n;
    cin >> n;
    map<string, int> maps;
    bool output = false;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;
      str = del(str);
      str = trans(str);
      if (maps.find(str) != maps.end()) {
        maps[str]++;
        output = true;
      }
      else maps[str] = 1;
    }
    for (map<string,int>::iterator  it = maps.begin(); it != maps.end(); ++it){
      if (output == false) {cout << "No duplicates." << endl; return 0;}
      if (it -> second > 1) cout << turns(it -> first) << " " << it->second << endl;
    }
    return 0;
}
