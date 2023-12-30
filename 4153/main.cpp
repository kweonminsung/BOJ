#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  int a1, b1, c1;

  cin >> a >> b >> c;
  while (!(a == 0 && b == 0 && c == 0)) {
    c1 = max(a, max(b, c));
    a1 = min(a, min(b, c));
    b1 = a + b + c - a1 - c1;

    if (c1 * c1 == a1 * a1 + b1 * b1)
      cout << "right\n";
    else
      cout << "wrong\n";

    cin >> a >> b >> c;
  }
}
