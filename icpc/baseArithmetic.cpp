//Problem        : Base Arithmetic
//Language       : C++
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Prlong long out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
using namespace std;
long long read();
long long sum(long long s1, long long s2);
int main() {
    long long s1 = read();
    long long s2 = read();
    cout << sum( s1,  s2) << endl;
    return 0;
}

long long sum(long long s1, long long s2) {
  long long r = s1 + s2;
  return r;
}

long long read() {
  string line;
  cin >> line;
  int digits[line.length()];
  int p = int(line.at(0));
  int base;
  digits[0] = p < 58 ? p - '0' : p - 'A' + 10;
  for (int i = 1; i < line.length(); i++) {
      int q = int(line.at(i));
      if (p < q) p = q;
      digits[i] = q < 58 ? q - '0' : q  - 'A' + 10;
  }
  if (p < 58) base = p - '0';
  else base = p - 'A' + 10;
  base ++;
  long long sum;
  for (int i = 0; i < line.length(); i ++) {
    sum = sum + pow(base, i) * digits[line.length() - 1 - i];
  }
  return sum ;
}
