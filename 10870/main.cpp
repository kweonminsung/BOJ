#include <bits/stdc++.h>

using namespace std;

long func(long n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  return func(n - 1) + func(n - 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long n;
  cin >> n;
  cout << func(n);
}
