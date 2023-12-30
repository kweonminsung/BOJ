#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2) {
  if (p1.second == p2.second) {
    if (p1.first.length() == p2.first.length())
      return (p1.first < p2.first);
    return (p1.first.length() > p2.first.length());
  } else
    return (p1.second > p2.second);
}

int main(void) {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> M;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    if (input.length() >= m)
      M[input]++;
  }

  vector<pair<string, int>> V(M.begin(), M.end());

  sort(V.begin(), V.end(), cmp);
  for (auto p : V)
    cout << p.first << "\n";
}