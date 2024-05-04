#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int v1x = x2 - x1, v1y = y2 - y1;
  int v2x = x3 - x2, v2y = y3 - y2;

  int cp = v1x * v2y - v2x * v1y;

  if (cp > 0)
    cout << 1;
  else if (cp < 0)
    cout << -1;
  else
    cout << 0;
}
