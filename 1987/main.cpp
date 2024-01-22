#include <bits/stdc++.h>

using namespace std;

int r, c, maxCnt = 0;
string board[20];
int dist[20][20];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++)
    cin >> board[i];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < r; k++)
        fill(dist[k], dist[k] + c, -1);

      stack<pair<int, int>> S;
      set<char> Set;
      S.push({i, j});
      dist[i][j] = 0;
      Set.insert(board[i][j]);

      while (!S.empty()) {
        auto cur = S.top();
        S.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];

          if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
          if (dist[nx][ny] != -1)
            continue;

          dist[nx][ny] = dist[cur.first][cur.second] + 1;
          S.push({nx, ny});
          Set.insert(board[nx][ny]);
          maxCnt = max(maxCnt, dist[nx][ny]);
        }
      }
    }
  }

  cout << maxCnt;
}
