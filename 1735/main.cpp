#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n) {
  for (int i = min(m, n); i >= 1; i--) {
    if (m % i == 0 && n % i == 0)
      return i;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int aU, aD, bU, bD;
  cin >> aU >> aD >> bU >> bD;

  int u = aU * bD + bU * aD;
  int d = aD * bD;

  int temp = gcd(u, d);

  cout << (u / temp) << " " << (d / temp);
}
