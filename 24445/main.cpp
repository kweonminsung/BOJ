#include <bits/stdc++.h>

using namespace std;

int n, m, r, cnt = 1;
set<int> e[100001];
int vis[100001];

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

  queue<int> Q;
  Q.push(r);
  vis[r] = cnt;
  cnt++;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (auto riter = e[cur].rbegin(); riter != e[cur].rend(); riter++) {
      if (vis[*riter] != 0)
        continue;

      vis[*riter] = cnt;
      Q.push(*riter);
      cnt++;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << vis[i] << "\n";
}
