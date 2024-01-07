#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[502][502];
  int vis[502][502];

  queue<pair<int, int>> Q;

  int n, m;
  cin >> n >> m;

  int cnt = 0, maxN = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1 && vis[i][j] == 0) {
        int size = 1;
        cnt++;
        vis[i][j] = 1;
        Q.push({i, j});

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (vis[nx][ny] || arr[nx][ny] == 0)
              continue;

            vis[nx][ny] = 1;
            size++;
            Q.push({nx, ny});
          }
        }

        maxN = max(maxN, size);
      }
    }
  }

  cout << cnt << "\n" << maxN;
}
