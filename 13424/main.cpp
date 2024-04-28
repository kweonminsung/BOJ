#include <bits/stdc++.h>

using namespace std;

int T, N, M, K;

const int INF = 1e9;

int dist[101];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> N >> M;

    int minI, minN = INT_MAX;

    vector<pair<int, int>> adj[101];
    vector<int> loc;

    for (int j = 0; j < M; j++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({c, b});
      adj[b].push_back({c, a});
    }

    cin >> K;
    for (int j = 0; j < K; j++) {
      int a;
      cin >> a;
      loc.push_back(a);
    }

    for (int j = 1; j <= N; j++) {
      fill(dist, dist + N + 1, INF);

      dist[j] = 0;
      pq.push({0, j});

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

      int temp = 0;
      for (int x : loc)
        temp += dist[x];

      if (minN > temp) {
        minI = j;
        minN = temp;
      } else if (minN == temp && minI > j)
        minI = j;
    }

    cout << minI << "\n";
  }
}
