#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, e;
  cin >> n >> e;

  vector<int> arr[102];
  int vis[102];
  int cnt = 0;

  queue<int> Q;

  for (int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    arr[x].push_back(y);
    arr[y].push_back(x);
  }

  Q.push(1);
  vis[1] = 1;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    cnt++;

    for (auto nxt : arr[cur]) {
      if (vis[nxt])
        continue;
      vis[nxt] = 1;
      Q.push(nxt);
    }
  }

  cout << cnt - 1;
}
