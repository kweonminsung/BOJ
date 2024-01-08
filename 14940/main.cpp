#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];
int dis[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;

int n, m;

void bfs() {
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dis[nx][ny] != -1 || board[nx][ny] == 0)
        continue;

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    fill(dis[i], dis[i] + m, -1);

    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0)
        dis[i][j] = 0;
      if (board[i][j] == 2) {
        Q.push({i, j});
        dis[i][j] = 0;
      }
    }
  }

  bfs();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dis[i][j] << " ";
    }
    cout << "\n";
  }
}
