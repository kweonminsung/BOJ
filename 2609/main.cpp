#include <bits/stdc++.h>

using namespace std;

int gcd(int m, int n) {
  for (int i = min(m, n); i >= 1; i--) {
    if (m % i == 0 && n % i == 0)
      return i;
  }
}

int lcm(int m, int n) {
  int i = m;
  while (i % n != 0)
    i += m;
  return i;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n;
  cin >> m >> n;

  cout << gcd(m, n) << "\n" << lcm(m, n);
}
