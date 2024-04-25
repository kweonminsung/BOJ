#include <bits/stdc++.h>

using namespace std;

int N, M, X;

vector<pair<int, int>> adj[1001];
int dist[1001][1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> X;

  for (int i = 1; i <= N; i++)
    fill(dist[i], dist[i] + N + 1, INF);

  for (int i = 0; i < M; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
  }

  for (int i = 1; i <= N; i++) {
    dist[i][i] = 0;
    pq.push({0, i});

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();

      if (cur.first != dist[i][cur.second])
        continue;
      for (auto nxt : adj[cur.second]) {
        if (dist[i][nxt.second] <= dist[i][cur.second] + nxt.first)
          continue;
        dist[i][nxt.second] = dist[i][cur.second] + nxt.first;
        pq.push({dist[i][nxt.second], nxt.second});
      }
    }
  }

  int result[1001];
  for (int i = 1; i <= N; i++) {
    result[i] = dist[i][X] + dist[X][i];
  }

  cout << *max_element(result + 1, result + N + 1);
}
