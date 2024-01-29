#include <bits/stdc++.h>

using namespace std;

int r, c, maxCnt = 0;
string board[20];
bool vis[26];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(pair<int, int> cur, int k) {
  maxCnt = max(maxCnt, k);
  for (int dir = 0; dir < 4; dir++) {
    int nx = cur.first + dx[dir];
    int ny = cur.second + dy[dir];

    if (nx < 0 || nx >= r || ny < 0 || ny >= c)
      continue;
    if (vis[board[nx][ny] - 'A'])
      continue;

    vis[board[nx][ny] - 'A'] = true;
    dfs({nx, ny}, k + 1);
    vis[board[nx][ny] - 'A'] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; i++)
    cin >> board[i];

  vis[board[0][0] - 'A'] = true;
  dfs({0, 0}, 1);

  cout << maxCnt;
}
