#include <bits/stdc++.h>

using namespace std;

int N, st, en;

vector<pair<int, int>> adj[1001];
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

string state[1001];

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  fill(dist, dist + N + 1, INF);

  for (int i = 1; i <= N; i++) {
    cin >> state[i];
  }

  cin >> st >> en;

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      int w = 0;
      for (int c = 0; c < state[i].length(); c++) {
        w += (state[i][c] - state[j][c]) * (state[i][c] - state[j][c]);
      }

      adj[i].push_back({w, j});
      adj[j].push_back({w, i});
    }
  }

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
    }
  }

  cout << dist[en];
}
