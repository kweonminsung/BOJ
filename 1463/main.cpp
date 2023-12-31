#include <bits/stdc++.h>

using namespace std;

int F[1000000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  F[1] = 0;

  for (int i = 2; i <= n; i++) {
    F[i] = F[i - 1] + 1;
    if (i % 2 == 0)
      F[i] = min(F[i], F[i / 2] + 1);
    if (i % 3 == 0)
      F[i] = min(F[i], F[i / 3] + 1);
  }

  cout << F[n];
}