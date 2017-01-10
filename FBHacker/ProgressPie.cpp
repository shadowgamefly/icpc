#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159265
using namespace std;

int main(){
  int num;
  cin >> num;
  for (int i = 1; i < num + 1; i++) {
    int per;
    double x;
    double y;
    bool white;
    cin >> per >> x >> y;
    // out of the circle is white
    double distance = sqrt((x - 50) * (x - 50) + (y - 50)*(y - 50));
    if (distance > 50) {
      cout << "Case #" << i << ": " << "white" << endl;
      continue;
    }
    // when y == 50 can't compute tan value
    if (y == 50) {
      if (per > 0 && x >= 50) cout << "Case #" << i << ": " << "black" << endl;
      else if (x < 50 && per >= 50) cout << "Case #" << i << ": " << "black" << endl;
      else {cout << "Case #" << i << ": " << "white" << endl;  }
      continue;
    }
    // other cases
    double tanOfPoint = (x-50)/(y-50);
    double angleOfPoint_fake = atan(tanOfPoint) * 50 / PI;
    double angleOfPoint = angleOfPoint_fake < 0 ? angleOfPoint_fake + 100 : angleOfPoint_fake;
    //cout << angleOfPoint << endl;
    if (angleOfPoint > per) cout << "Case #" << i << ": " << "white" << endl;
    else  cout << "Case #" << i << ": " << "black" << endl;
  }
  return 0;
}
