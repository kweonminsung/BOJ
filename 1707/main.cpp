#include <bits/stdc++.h>

using namespace std;

int v, e;

int vis[20002];
vector<int> E[20002];

bool bfs() {
  for (int s = 1; s <= v; s++) {
    if (vis[s] != 0)
      continue;

    queue<int> Q;
    Q.push(s);
    vis[s] = 1;

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (int nxt : E[cur]) {
        if (vis[nxt] != 0) {
          if (vis[nxt] == vis[cur])
            return false;
          continue;
        }

        vis[nxt] = (vis[cur] == 1) ? -1 : 1;
        Q.push(nxt);
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> v >> e;

    fill(vis, vis + v + 1, 0);

    for (int j = 0; j < v + 1; j++)
      E[j].clear();

    for (int j = 0; j < e; j++) {
      int from, to;
      cin >> from >> to;
      E[from].push_back(to);
      E[to].push_back(from);
    }

    cout << (bfs() ? "YES\n" : "NO\n");
  }
}
