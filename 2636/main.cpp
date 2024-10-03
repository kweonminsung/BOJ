#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[102][102];
bool vis[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int check() {
  int cnt = 0;
  for (int i = 1; i < N + 1; i++)
    for (int j = 1; j < M + 1; j++)
      if (board[i][j] == 1 || board[i][j] == 2)
        cnt++;

  return cnt;
}

void colorToErase() {
  for (int i = 0; i <= N + 1; i++)
    fill(vis[i], vis[i] + M + 1, false);

  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx > N + 2 || ny < 0 || ny > M + 2)
        continue;
      if (vis[nx][ny])
        continue;

      if (board[nx][ny] == 1 || board[nx][ny] == 2) {
        board[nx][ny] = 2;
        continue;
      }

      q.push({nx, ny});
      vis[nx][ny] = true;
    }
  }
}

void erase() {
  for (int i = 1; i < N + 1; i++)
    for (int j = 1; j < M + 1; j++)
      if (board[i][j] == 2)
        board[i][j] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i < N + 1; i++)
    for (int j = 1; j < M + 1; j++)
      cin >> board[i][j];

  int t = 0, remain = check();
  while (true) {
    colorToErase();
    erase();
    t++;

    int result = check();
    if (result == 0) {
      cout << t << "\n" << remain;
      return 0;
    }
    remain = result;
  }
}
