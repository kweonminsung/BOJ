#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s.insert({y, x});
  }

  for (auto i : s) {
    cout << i.second << " " << i.first << "\n";
  }
}
