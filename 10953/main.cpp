#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    cout << (s[0] + s[2] - 2 * '0') << "\n";
  }
}
