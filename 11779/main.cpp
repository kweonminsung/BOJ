#include <bits/stdc++.h>

using namespace std;

int n, m, st, en;

vector<pair<int, int>> adj[1001];
int dist[1001];
int pre[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(dist, dist + n + 1, INF);

  for (int i = 0; i < m; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
  }

  cin >> st >> en;

  dist[st] = 0;
  pq.push({0, st});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (cur.first != dist[cur.second])
      continue;
    for (auto nxt : adj[cur.second]) {
      if (dist[nxt.second] <= dist[cur.second] + nxt.first)
        continue;
      dist[nxt.second] = dist[cur.second] + nxt.first;
      pq.push({dist[nxt.second], nxt.second});
      pre[nxt.second] = cur.second;
    }
  }

  cout << dist[en] << "\n";

  vector<int> path;
  int cur = en;
  while (cur != st) {
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(), path.end());

  cout << path.size() << "\n";

  for (int node : path)
    cout << node << " ";
}
