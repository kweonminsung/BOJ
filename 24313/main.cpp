#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a1, a0;
  cin >> a1 >> a0;
  int c;
  cin >> c;
  int n0;
  cin >> n0;

  if (a1 * n0 + a0 <= c * n0 && c >= a1)
    cout << 1;
  else
    cout << 0;
}
