#include <bits/stdc++.h>

using namespace std;

int V, E, K;

vector<pair<int, int>> adj[20005];
int dist[20005];

const int INF = 1e9;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E >> K;
  fill(dist, dist + V + 1, INF);

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  dist[K] = 0;
  pq.push({dist[K], K});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (dist[cur.second] != cur.first)
      continue;
    for (auto nxt : adj[cur.second]) {
      if (dist[nxt.second] <= dist[cur.second] + nxt.first)
        continue;
      dist[nxt.second] = dist[cur.second] + nxt.first;
      pq.push({dist[nxt.second], nxt.second});
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << "\n";
  }
}
