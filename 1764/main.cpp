#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, cnt = 0;
  cin >> n >> m;
  map<string, int> j;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    j[input] = 1;
  }

  set<string> s;
  while (m--) {
    string input;
    cin >> input;
    if (j[input] == 1) {
      s.insert(input);
      cnt++;
    }
  }

  cout << cnt << "\n";
  for (auto i : s)
    cout << i << "\n";
}
