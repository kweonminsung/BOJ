#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, m;
  cin >> h >> m;

  if (m - 45 < 0) {
    if (h - 1 < 0)
      h = 24;
    cout << h - 1 << " " << m + 15;
  } else
    cout << h << " " << m - 45;
}
