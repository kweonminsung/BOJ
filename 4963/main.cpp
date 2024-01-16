#include <bits/stdc++.h>
using namespace std;

int w, h;
;
int board[50][50];
bool vis[50][50];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, -1, 0, 1, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> w >> h;

  while (!(w == 0 && h == 0)) {
    for (int i = 0; i < h; i++)
      fill(vis[i], vis[i] + w, false);

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> board[i][j];
      }
    }

    int cnt = 0;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == 1 && vis[i][j] == false) {
          cnt++;
          queue<pair<int, int>> Q;

          Q.push({i, j});
          vis[i][j] = true;

          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++) {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];

              if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
              if (vis[nx][ny] == 1 || board[nx][ny] == 0)
                continue;

              vis[nx][ny] = true;
              Q.push({nx, ny});
            }
          }
        }
      }
    }

    cout << cnt << "\n";
    cin >> w >> h;
  }
}
