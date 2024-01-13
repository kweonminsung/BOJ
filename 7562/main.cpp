#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  int dist[301][301];

  for (int i = 0; i < t; i++) {
    int l, fromX, fromY, toX, toY;
    cin >> l >> fromX >> fromY >> toX >> toY;

    if (fromX == toX && fromY == toY) {
      cout << 0 << "\n";
      continue;
    }

    for (int j = 0; j < l; j++)
      fill(dist[j], dist[j] + l, -1);

    queue<pair<int, int>> Q;
    Q.push({fromX, fromY});
    dist[fromX][fromY] = 0;

    while (!Q.empty()) {
      bool endFlag = false;
      auto cur = Q.front();
      Q.pop();

      for (int dir = 0; dir < 8; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (nx == toX && ny == toY) {
          cout << dist[cur.first][cur.second] + 1 << "\n";
          endFlag = true;
          break;
        }
        if (nx < 0 || nx >= l || ny < 0 || ny >= l)
          continue;
        if (dist[nx][ny] != -1)
          continue;

        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        Q.push({nx, ny});
      }
      if (endFlag)
        break;
    }
  }
}
