#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> adj[10001];
int parent[10001];

int maxI, maxD = 0;

void dfs(int k, int sum) {
  for (auto nxt : adj[k]) {
    if (parent[nxt.second] != 0)
      continue;

    parent[nxt.second] = k;
    if (sum + nxt.first > maxD) {
      maxD = sum + nxt.first;
      maxI = nxt.second;
    }

    dfs(nxt.second, sum + nxt.first);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int from, to, w;
    cin >> from >> to >> w;

    adj[from].push_back({w, to});
    adj[to].push_back({w, from});
  }

  parent[1] = -1;
  dfs(1, 0);
  fill(parent, parent + n + 1, 0);
  parent[maxI] = -1;
  dfs(maxI, 0);

  cout << maxD;
}
