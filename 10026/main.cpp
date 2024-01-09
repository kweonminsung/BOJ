#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;
string board[102];
int vis[102][102];

int bfs(bool canSee) {
  int cnt = 0;
  queue<pair<int, int>> Q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] == 0) {
        cnt++;
        char color = board[i][j];

        Q.push({i, j});
        vis[i][j] = 1;

        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (vis[nx][ny] != 0)
              continue;
            if (color != board[nx][ny]) {
              if (canSee)
                continue;
              if (color == 'R' && board[nx][ny] == 'B' ||
                  color == 'B' && board[nx][ny] == 'R' ||
                  color == 'G' && board[nx][ny] == 'B' ||
                  color == 'B' && board[nx][ny] == 'G')
                continue;
            }

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  cout << bfs(true) << " ";
  for (int i = 0; i < n; i++)
    fill(vis[i], vis[i] + n, 0);
  cout << bfs(false);
}
