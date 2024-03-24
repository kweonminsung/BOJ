#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int board[50][50];
bool vis[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  int day = -1;

  while (true) {
    day++;
    int groups = 0;

    for (int i = 0; i < n; i++)
      fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vis[i][j])
          continue;

        vector<pair<int, int>> group;
        int total = 0;

        queue<pair<int, int>> Q;
        Q.push({i, j});
        vis[i][j] = true;
        group.push_back({i, j});
        total += board[i][j];

        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (vis[nx][ny])
              continue;
            if (abs(board[nx][ny] - board[cur.first][cur.second]) < l ||
                abs(board[nx][ny] - board[cur.first][cur.second]) > r)
              continue;

            group.push_back({nx, ny});
            total += board[nx][ny];

            vis[nx][ny] = true;
            Q.push({nx, ny});
          }
        }

        if (group.size() > 1)
          groups++;

        int groupN = total / group.size();
        for (auto g : group) {
          board[g.first][g.second] = groupN;
        }
      }
    }

    if (groups == 0)
      break;
  }

  cout << day;
}
