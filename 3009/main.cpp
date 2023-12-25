#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  cout << (a1 == b1 ? c1 : (a1 == c1 ? b1 : a1)) << " "
       << (a2 == b2 ? c2 : (a2 == c2 ? b2 : a2));
}
