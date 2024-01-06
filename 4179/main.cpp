#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string board[1000];
  int dist[1000][1000];
  int fireDist[1000][1000];

  int n, m;
  cin >> n >> m;

  queue<pair<int, int>> Q;
  queue<pair<int, int>> fQ;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < n; i++) {
    fill(dist[i], dist[i] + m, -1);
    fill(fireDist[i], fireDist[i] + m, -1);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'J') {
        dist[i][j] = 0;
        Q.push({i, j});
      }
      if (board[i][j] == 'F') {
        fireDist[i][j] = 0;
        fQ.push({i, j});
      }
    }
  }

  while (!fQ.empty()) {
    auto cur = fQ.front();
    fQ.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (board[nx][ny] == '#' || fireDist[nx][ny] != -1)
        continue;

      fireDist[nx][ny] = fireDist[cur.first][cur.second] + 1;

      fQ.push({nx, ny});
    }
  }

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        cout << dist[cur.first][cur.second] + 1;
        return 0;
      }
      if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
        continue;
      if (fireDist[nx][ny] != -1 &&
          fireDist[nx][ny] <= dist[cur.first][cur.second] + 1)
        continue;

      dist[nx][ny] = dist[cur.first][cur.second] + 1;

      Q.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";
}
