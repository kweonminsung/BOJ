#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, vector<string>> m;
  set<int> s;

  for (int i = 0; i < n; i++) {
    int num;
    string str;
    cin >> num >> str;
    m[num].push_back(str);
    s.insert(num);
  }

  for (auto i : s)
    for (auto j : m[i])
      cout << i << " " << j << "\n";
}
