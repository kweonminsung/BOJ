#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  set<int> s;

  for (int i = 0; i < n + m; i++) {
    int input;
    cin >> input;
    s.insert(input);
  }

  cout << 2 * s.size() - m - n;
}
