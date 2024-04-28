#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;

vector<pair<int, int>> adj[1001];
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x >> y;
  fill(dist, dist + n + 1, INF);

  for (int i = 0; i < m; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
    adj[to].push_back({w, from});
  }

  dist[y] = 0;
  pq.push({0, y});

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
  sort(dist, dist + n);

  int day = 0, index = 1;
  bool visitAll = true;
  while (true) {
    if (index == n)
      break;
    if (dist[index] * 2 > x) {
      visitAll = false;
      break;
    }

    int temp = 0;
    while (index < n && temp + dist[index] * 2 <= x) {
      temp += dist[index] * 2;
      index++;
    }

    day++;
  }

  cout << (visitAll ? day : -1);
}
