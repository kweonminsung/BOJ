#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> edge[102];
  int vis[102];
  int reach[102][102];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int input;
      cin >> input;

      if (input == 1)
        edge[i].push_back(j);
    }
  }

  for (int i = 0; i < n; i++) {
    fill(vis, vis + n, 0);

    queue<int> Q;
    Q.push(i);
    vis[i] = 0;
    int originFlag = 0;

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      reach[i][cur] = 1;

      if (cur == i)
        originFlag++;

      for (auto nxt : edge[cur]) {
        if (vis[nxt])
          continue;

        vis[nxt] = 1;
        Q.push(nxt);
      }
    }

    reach[i][i] = originFlag >= 2 ? 1 : 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << reach[i][j] << " ";
    }
    cout << "\n";
  }
}
