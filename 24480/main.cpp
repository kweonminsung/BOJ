#include <bits/stdc++.h>

using namespace std;

int n, m, r, cnt = 1;
set<int> e[100001];
int vis[100001];

void dfs(int r) {
  vis[r] = cnt;
  cnt++;

  for (auto riter = e[r].rbegin(); riter != e[r].rend(); riter++) {
    if (vis[*riter] == 0)
      dfs(*riter);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    e[from].insert(to);
    e[to].insert(from);
  }

  dfs(r);

  for (int i = 1; i <= n; i++)
    cout << vis[i] << "\n";
}
