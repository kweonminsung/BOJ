#include <bits/stdc++.h>

using namespace std;

int n, a1, a2, m;
vector<int> edges[101];
int dist[101];

void bfs(int k) {
  queue<int> Q;
  Q.push(k);
  dist[k] = 0;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int e : edges[cur]) {
      if (e == a2) {
        cout << dist[cur] + 1;
        return;
      }
      if (dist[e] != -1)
        continue;

      dist[e] = dist[cur] + 1;
      Q.push(e);
    }
  }

  cout << -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a1 >> a2 >> m;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }
  fill(dist, dist + n + 1, -1);
  bfs(a1);
}
