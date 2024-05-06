#include <bits/stdc++.h>

using namespace std;

int V;

vector<pair<int, int>> adj[100001];
int parent[100001];

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

  cin >> V;

  for (int i = 0; i < V; i++) {
    int from, to, w;

    cin >> from >> to;

    while (to != -1) {
      cin >> w;
      adj[from].push_back({w, to});
      cin >> to;
    }
  }
  parent[1] = -1;
  dfs(1, 0);
  fill(parent, parent + V + 1, 0);
  parent[maxI] = -1;
  dfs(maxI, 0);

  cout << maxD;
}
