#include <iostream>
#include <vector>
#define MAX 1000000
#include <math.h>
using namespace std;

int gcd(int a, int b) {
		if (a == 0) return b;
		if (b == 0) return a;
		return gcd(b, a%b);
}

//if p is a plausible prime for given partition
bool plausible(int p, int partition, vector<int> &v, vector<int> &sieve) {
  int n = v.size();
  int partSoFar = 0;
  int i = 0;
  while(i < n) {
    if (partSoFar >= partition) {
      return false;
    }
    int curGCD = v[i];
		if (sieve[curGCD] < p) return false;
		i++;
    while (i < n) {
				curGCD = gcd(curGCD, v[i]);
				if (sieve[curGCD] < p) break;
				else i++;
			}
    partSoFar++;
  }
  return true;
}

int main() {
  // generate prime nums
  vector<int> sieve;
  for (int i = 0; i < MAX + 1; i++) {
    sieve.push_back(-1);
  }
	for (int i=2; i< sieve.size(); i++) {
			if (sieve[i] == -1) {
				for (int j=i; j<sieve.size(); j+=i)
					sieve[j] = i;
			}
		}
	int numPrime = 0;
	for (int i=2; i<sieve.size(); i++) {
		if (sieve[i] == i) {
			numPrime++;
    }
  }
	vector<int> primes;
	for (int i=2; i<sieve.size(); i++) {
		if (sieve[i] == i) {
			primes.push_back(i);
    }
  }
//  for (int i = 0; i < numPrime; i++) {
//    cout << primes[i] << endl;
//  }

  //input
  int num, partition;
  cin >> num >> partition;
  vector<int> v;
  for (int i = 0; i < num; i++) {
    int cur;
    cin >> cur;
    v.push_back(cur);
  }

  // for (int i = 0; i < num; i++) {
  //   cout << v[i] << " ";
  // }
  // cout << endl;

  if (!plausible(2, partition, v, sieve)) {
			cout << "0" << endl;
    }
	else {
			// Binary search over what is plausible.
			int low = 0, high = primes.size()-1;
			while (low < high-1) {
				int mid = (low+high)/2;
				if (plausible(primes[mid], partition, v, sieve))
					low = mid;
				else
					high = mid-1;
			}

			// Walk the last step.
			while (low < primes.size() && plausible(primes[low], partition, v, sieve)) low++;
  		cout << primes[low-1] << endl;
		}


}
