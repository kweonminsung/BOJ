#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int minH = 999999, minD = 999999;

  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    minH = min(n, minH);
  }

  for (int i = 0; i < 2; i++) {
    int n;
    cin >> n;
    minD = min(n, minD);
  }

  cout << minH + minD - 50;
}
