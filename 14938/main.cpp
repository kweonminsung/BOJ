#include <bits/stdc++.h>

using namespace std;

int n, m, r;

vector<pair<int, int>> adj[101];
int dist[101][101], value[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++)
    fill(dist[i], dist[i] + n + 1, INF);

  for (int i = 1; i <= n; i++) {
    cin >> value[i];
  }

  for (int i = 1; i <= r; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
    adj[to].push_back({w, from});
  }

  for (int i = 1; i <= n; i++) {
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

  int maxN = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 0;

    for (int j = 1; j <= n; j++) {
      if (dist[i][j] <= m) {
        temp += value[j];
      }
    }

    maxN = max(maxN, temp);
  }

  cout << maxN;
}
