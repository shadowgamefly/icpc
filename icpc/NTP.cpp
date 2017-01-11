#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1 ; i < n+1; i++) {
    int p;
    cin >> p;
    cout << "Case #" << i << ": " << p/3 <<endl;
  }
  return 0;
}
