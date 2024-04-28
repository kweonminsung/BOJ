#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<pair<int, int>> adj[50001];
int dist[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  fill(dist, dist + N + 1, INF);

  for (int i = 0; i < M; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
    adj[to].push_back({w, from});
  }

  dist[1] = 0;
  pq.push({0, 1});

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
    }
  }

  cout << dist[N];
}
