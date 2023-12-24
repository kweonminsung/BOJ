#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, cnt = 0;
  cin >> n >> m;
  set<string> s;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    s.insert(input);
  }
  for (int i = 0; i < m; i++) {
    string input;
    cin >> input;
    if (s.find(input) != s.end())
      cnt++;
  }

  cout << cnt;
}
