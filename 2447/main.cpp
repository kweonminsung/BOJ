#include <bits/stdc++.h>

using namespace std;

bool check(int x, int y, int n) {
  if (x < 3 && y < 3) {
    if (x == 1 && y == 1)
      return false;
    return true;
  }

  if (x / n == 1 && y / n == 1)
    return false;

  return check(x % n, y % n, n / 3);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (check(i, j, n) ? "*" : " ");
    }
    cout << "\n";
  }
}