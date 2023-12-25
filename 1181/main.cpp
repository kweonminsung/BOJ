#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<pair<int, string>> s;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    s.insert({str.size(), str});
  }

  for (auto i : s) {
    cout << i.second << "\n";
  }
}
