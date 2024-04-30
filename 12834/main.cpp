#include <bits/stdc++.h>

using namespace std;

int N, V, E, A, B;
int team[101];

vector<pair<int, int>> adj[1001];
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> V >> E >> A >> B;

  for (int i = 0; i < N; i++) {
    cin >> team[i];
  }

  for (int i = 0; i < E; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to});
    adj[to].push_back({w, from});
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    fill(dist, dist + V + 1, INF);

    int st = team[i];

    pq.push({0, st});
    dist[st] = 0;

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

    result += (dist[A] == INF ? -1 : dist[A]) + (dist[B] == INF ? -1 : dist[B]);
  }

  cout << result;
}
