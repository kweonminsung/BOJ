#include <bits/stdc++.h>

using namespace std;

long func(long n) {
  if (n == 1 || n == 0)
    return 1;

  return n * func(n - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long n;
  cin >> n;
  cout << func(n);
}
