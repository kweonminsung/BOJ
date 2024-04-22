#include <bits/stdc++.h>

using namespace std;

int N, M;
int start, finish;

vector<pair<int, int>> adj[2001];
int dist[2001];

const int INF = 1e9;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  fill(dist, dist + N + 1, INF);

  for (int i = 0; i < M; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    adj[from].push_back({weight, to});
  }

  cin >> start >> finish;

  dist[start] = 0;
  pq.push({0, start});

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

  cout << dist[finish];
}
