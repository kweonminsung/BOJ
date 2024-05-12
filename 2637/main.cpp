#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[101];
int deg[101], deg1[101];
int cnt[101];

queue<pair<int, int>> q;
vector<int> baseComp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to, w;
    cin >> from >> to >> w;
    adj[from].push_back({to, w});
    deg[to]++;
    deg1[from]++;
  }

  for (int i = 1; i <= N; i++)
    if (deg1[i] == 0)
      baseComp.push_back(i);

  q.push({N, 0});
  cnt[N] = 1;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : adj[cur.first]) {
      deg[nxt.first]--;
      cnt[nxt.first] += nxt.second * cnt[cur.first];
      if (deg[nxt.first] == 0)
        q.push(nxt);
    }
  }

  for (int x : baseComp)
    cout << x << " " << cnt[x] << "\n";
}
