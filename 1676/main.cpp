#include <bits/stdc++.h>

using namespace std;

int cnt(int n, int i) {
  int result = 0;

  while (true) {
    if (n % i == 0) {
      n /= i;
      result++;
    } else
      break;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int five = 0, two = 0;

  for (int i = 1; i <= n; i++) {
    five += cnt(i, 5);
    two += cnt(i, 2);
  }

  cout << min(five, two);
}
