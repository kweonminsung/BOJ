#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int cnt = 0;
  map<string, bool> m;
  set<string> s;

  m["ChongChong"] = true;
  s.insert("ChongChong");

  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;

    if (m[a] == true || m[b] == true) {
      m[a] = true;
      m[b] = true;
      s.insert(a);
      s.insert(b);
    }
  }

  for (auto i : s) {
    if (m[i])
      cnt++;
  }

  cout << cnt;
}
