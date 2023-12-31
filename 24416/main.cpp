#include <bits/stdc++.h>

using namespace std;

int f[50];
int cnt = 0, cntD = 0;

int fib(int n) {
  if (n == 1 || n == 2)
    return 1;
  else {
    cnt++;
    return (fib(n - 1) + fib(n - 2));
  }
}

int fibonacci(int n) {
  if (n == 1 || n == 2)
    return 1;

  for (int i = 3; i <= n; i++) {
    cntD++;
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  fib(n);
  fibonacci(n);

  cout << cnt + 1 << " " << cntD;
}
