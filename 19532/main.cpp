#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  cout << ((b * f - c * e) / (b * d - a * e)) << " "
       << ((a * f - d * c) / (a * e - b * d));
}
