#include <bits/stdc++.h>

using namespace std;

int func(int n) {
  if (n == 1)
    return 3;
  return 2 * func(n - 1) - 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  cout << func(n) * func(n);
}
