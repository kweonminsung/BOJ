
#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<tuple<int, int, int>> adj[1001];
int dist[1001];
int pre[1001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
               greater<tuple<int, int, int>>>
    pq;
int edgeN[1001][1001];

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= M; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({w, to, i});
    adj[to].push_back({w, from, i});
    edgeN[from][to] = i;
    edgeN[to][from] = i;
  }

  fill(dist, dist + N + 1, INF);

  dist[1] = 0;
  pq.push({0, 1, 0});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (get<0>(cur) != dist[get<1>(cur)])
      continue;
    for (auto nxt : adj[get<1>(cur)]) {
      if (dist[get<1>(nxt)] <= dist[get<1>(cur)] + get<0>(nxt))
        continue;
      dist[get<1>(nxt)] = dist[get<1>(cur)] + get<0>(nxt);
      pq.push({dist[get<1>(nxt)], get<1>(nxt), get<2>(nxt)});
      pre[get<1>(nxt)] = get<1>(cur);
    }
  }

  vector<int> wayN;
  int cur = N;
  while (cur != 1) {
    wayN.push_back(edgeN[pre[cur]][cur]);
    cur = pre[cur];
  }

  int maxN = 0;
  for (int i : wayN) {
    fill(dist, dist + N + 1, INF);

    dist[1] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();

      if (get<0>(cur) != dist[get<1>(cur)])
        continue;
      for (auto nxt : adj[get<1>(cur)]) {
        if (get<2>(nxt) == i)
          continue;
        if (dist[get<1>(nxt)] <= dist[get<1>(cur)] + get<0>(nxt))
          continue;
        dist[get<1>(nxt)] = dist[get<1>(cur)] + get<0>(nxt);
        pq.push({dist[get<1>(nxt)], get<1>(nxt), get<2>(nxt)});
      }
    }
    maxN = max(maxN, dist[N]);
  }
  cout << maxN;
}
