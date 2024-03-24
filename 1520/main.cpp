#include <bits/stdc++.h>

using namespace std;

int m, n;
int board[500][500];
int dp[500][500];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(pair<int, int> cur) {
  if (cur.first == m - 1 && cur.second == n - 1)
    return 1;

  if (dp[cur.first][cur.second] != -1)
    return dp[cur.first][cur.second];

  int cnt = 0;

  for (int dir = 0; dir < 4; dir++) {
    int nx = cur.first + dx[dir];
    int ny = cur.second + dy[dir];

    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
      continue;
    if (board[nx][ny] >= board[cur.first][cur.second])
      continue;

    cnt += dfs({nx, ny});
  }

  dp[cur.first][cur.second] = cnt;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  for (int i = 0; i < m; i++)
    fill(dp[i], dp[i] + n, -1);

  cout << dfs({0, 0});
}
