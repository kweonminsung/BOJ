#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;

  queue<pair<ll, ll>> Q;
  Q.push({a, 1});

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    if (cur.first == b) {
      cout << cur.second;
      return 0;
    }
    if (cur.first * 2 <= b) {
      Q.push({cur.first * 2, cur.second + 1});
    }
    if (cur.first * 10 + 1 <= b) {
      Q.push({cur.first * 10 + 1, cur.second + 1});
    }
  }

  cout << -1;
}
