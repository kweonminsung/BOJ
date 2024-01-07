#include <bits/stdc++.h>

using namespace std;

int board[51][51];
int vis[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  int n, m, k, x, y;

  for (int i = 0; i < t; i++) {
    cin >> m >> n >> k;
    int cnt = 0;

    for (int j = 0; j < n; j++) {
      fill(board[j], board[j] + m, 0);
      fill(vis[j], vis[j] + m, 0);
    }

    for (int j = 0; j < k; j++) {
      cin >> y >> x;
      board[x][y] = 1;
    }

    queue<pair<int, int>> Q;

    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        if (board[j][l] && vis[j][l] == 0) {
          cnt++;
          Q.push({j, l});
          vis[j][l] = 1;

          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];

              if (nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
              if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                continue;

              vis[nx][ny] = 1;
              Q.push({nx, ny});
            }
          }
        }
      }
    }

    cout << cnt << "\n";
  }
}
