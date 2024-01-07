#include <bits/stdc++.h>

using namespace std;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int board[101][101][101];
  int dist[101][101][101];

  queue<tuple<int, int, int>> Q;

  int h, n, m;
  cin >> m >> n >> h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> board[i][j][k];
        if (board[i][j][k] == 1) {
          Q.push({i, j, k});
        }
        if (board[i][j][k] == 0) {
          dist[i][j][k] = -1;
        }
      }
    }
  }

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 6; dir++) {
      int nx = get<0>(cur) + dx[dir];
      int ny = get<1>(cur) + dy[dir];
      int nz = get<2>(cur) + dz[dir];

      if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m)
        continue;
      if (dist[nx][ny][nz] >= 0)
        continue;

      dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;

      Q.push({nx, ny, nz});
    }
  }

  int result = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int z = 0; z < m; z++) {
        if (dist[i][j][z] == -1) {
          cout << -1;
          return 0;
        }
        result = max(result, dist[i][j][z]);
      }
    }
  }

  cout << result;
}
