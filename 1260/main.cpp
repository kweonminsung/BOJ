#include <bits/stdc++.h>

using namespace std;

int n, m, start;
vector<int> arr[1001];
int vis[1001];

void bfs() {
  queue<int> Q;
  Q.push(start);
  vis[start] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    cout << cur << " ";
    Q.pop();

    for (auto j : arr[cur]) {
      if (vis[j] == 1)
        continue;
      vis[j] = 1;
      Q.push(j);
    }
  }
}

void dfs() {
  stack<int> S;
  S.push(start);
  while (!S.empty()) {
    auto cur = S.top();
    S.pop();

    if (vis[cur])
      continue;
    vis[cur] = 1;
    cout << cur << " ";

    for (int i = arr[cur].size() - 1; i >= 0; i--) {
      if (vis[arr[cur][i]] == 1)
        continue;
      S.push(arr[cur][i]);
    }
  }
}

void dfsR(int cur) {
  vis[cur] = 1;
  cout << cur << " ";
  for (auto nxt : arr[cur]) {
    if (vis[nxt] == 1)
      continue;
    dfsR(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> start;
  int cnt = 0;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    arr[from].push_back(to);
    arr[to].push_back(from);
  }

  for (int i = 1; i <= n; i++)
    sort(arr[i].begin(), arr[i].end());

  dfs();

  cout << "\n";
  fill(vis + 1, vis + n + 1, 0);

  bfs();
}
