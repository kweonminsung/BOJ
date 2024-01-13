#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
bool y[15], d1[29], d2[29];

void func(int r) {
  if (r == n) {
    cnt++;
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!y[i] && !d1[i - r + n] && !d2[i + r]) {
      y[i] = true;
      d1[i - r + n] = true;
      d2[i + r] = true;

      func(r + 1);

      y[i] = false;
      d1[i - r + n] = false;
      d2[i + r] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  func(0);
  cout << cnt;
}
