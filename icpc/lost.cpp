#include <iostream>
#include <vector>
#include <iomanip>
#define MIN 1E-15

using namespace std;
int main() {
  int nodes, edges;
  cin >> nodes >> edges;
  double probability[nodes];
  for (int i = 0; i < nodes; i++) {
    probability[i] = 0.0;
  }

  bool edge[nodes][nodes];

  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      edge[i][j] = false;
    }
  }

  int out[nodes];
  for (int i = 0; i < nodes; i++) {
    out[i] = 0;
  }

  for (int i = 0; i < edges; i++) {
    int start, end;
    cin >> start >> end;
    edge[start][end] = true;
    edge[end][start] = true;
    out[start]++;
    out[end]++;
   }

   //simulation

   probability[0] = 1.0;
   double sum = 1.0;
   double temp[nodes];
   double output = 0;
   double length = 1.0;


   for (int p = 0; p < 10000 ; p ++) {
     //simulate
     for (int i = 0; i < nodes; i++) {
         temp[i] = 0.0;
     }

     for (int i = 0 ; i < nodes; i++) {
       for (int j = 0; j < nodes; j++) {
         if (edge[i][j] == true) temp[j] += probability[i] / out[i];
       }
     }

  //   for (int i = 0; i < nodes; i++) {
  //       cout << temp[i] << endl;
  //   }

     for (int i = 0; i < nodes; i++) {
         probability[i] = temp[i];
     }

     output += probability[nodes-1] * double(length);
     sum -= probability[nodes - 1];
     probability[nodes - 1] = 0.0;
     length++;
//     cout << sum << endl;
   }
   printf("%.7lf\n",ex);
}
