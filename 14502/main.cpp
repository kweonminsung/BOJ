#include <bits/stdc++.h>

using namespace std;

int board[9][9];
int vis[9][9];
vector<pair<int, int>> space;
vector<pair<int, int>> start;

int n, m, wallN = 3;

int maxA = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
  for (auto sp : start) {
    queue<pair<int, int>> Q;
    Q.push(sp);
    vis[sp.first][sp.second] = 1;

    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();

      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (vis[nx][ny] != 0 || board[nx][ny] != 0)
          continue;

        vis[nx][ny] = 1;
        Q.push({nx, ny});
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0)
        cnt++;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1)
        wallN++;
      if (board[i][j] == 0)
        space.push_back({i, j});
      if (board[i][j] == 2)
        start.push_back({i, j});
    }
  }

  for (int i = 0; i < space.size() - 2; i++) {
    for (int j = i + 1; j < space.size() - 1; j++) {
      for (int k = j + 1; k < space.size(); k++) {

        for (int l = 0; l < n; l++)
          fill(vis[l], vis[l] + m, 0);

        board[space[i].first][space[i].second] = 1;
        board[space[j].first][space[j].second] = 1;
        board[space[k].first][space[k].second] = 1;
        maxA = max(bfs(), maxA);

        board[space[i].first][space[i].second] = 0;
        board[space[j].first][space[j].second] = 0;
        board[space[k].first][space[k].second] = 0;
      }
    }
  }
  cout << maxA - wallN;
}
