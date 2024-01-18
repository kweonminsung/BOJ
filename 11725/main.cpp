#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> edge[100001];
int parent[100001];

void dfs(int k) {
  for (int nxt : edge[k]) {
    if (parent[nxt] != 0)
      continue;

    parent[nxt] = k;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int from, to;
    cin >> from >> to;

    edge[from].push_back(to);
    edge[to].push_back(from);
  }

  dfs(1);

  for (int i = 2; i <= n; i++) {
    cout << parent[i] << "\n";
  }
}
