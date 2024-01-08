#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int cnt = 0;

  queue<int> Q;
  vector<int> arr[1001];
  int vis[1001];

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    arr[from].push_back(to);
    arr[to].push_back(from);
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      cnt++;
      vis[i] = 1;
      Q.push(i);

      while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (auto j : arr[cur]) {
          if (vis[j] == 1)
            continue;

          vis[j] = 1;
          Q.push(j);
        }
      }
    }
  }
  cout << cnt;
}
