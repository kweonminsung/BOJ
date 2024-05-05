#include <bits/stdc++.h>

using namespace std;

int R, C, T;
int board[51][51];
int diff[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> airc1 = {-1, -1}, airc2;

void air() {
  // 1
  for (int i = airc1.first - 2; i >= 0; i--)
    board[i + 1][0] = board[i][0];
  for (int i = 1; i <= C - 1; i++)
    board[0][i - 1] = board[0][i];
  for (int i = 1; i <= airc1.first; i++)
    board[i - 1][C - 1] = board[i][C - 1];
  for (int i = C - 2; i >= 1; i--)
    board[airc1.first][i + 1] = board[airc1.first][i];
  board[airc1.first][1] = 0;

  // 2
  for (int i = airc2.first + 2; i <= R - 1; i++)
    board[i - 1][0] = board[i][0];
  for (int i = 1; i <= C - 1; i++)
    board[R - 1][i - 1] = board[R - 1][i];
  for (int i = R - 2; i >= airc2.first; i--)
    board[i + 1][C - 1] = board[i][C - 1];
  for (int i = C - 2; i >= 1; i--)
    board[airc2.first][i + 1] = board[airc2.first][i];
  board[airc2.first][1] = 0;
}

void run() {
  for (int i = 0; i < R; i++)
    fill(diff[i], diff[i] + C, 0);

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int e = board[i][j] / 5;

      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
          continue;
        if ((nx == airc1.first && ny == airc1.second) ||
            (nx == airc2.first && ny == airc2.second))
          continue;

        diff[i][j] -= e;
        diff[nx][ny] += e;
      }
    }
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      board[i][j] += diff[i][j];
    }
  }

  air();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> T;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> board[i][j];

      if (board[i][j] == -1) {
        if (airc1.first == -1) {
          airc1 = {i, j};
        } else {
          airc2 = {i, j};
        }
      }
    }
  }

  while (T--)
    run();

  int result = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] > 0)
        result += board[i][j];
    }
  }
  cout << result;
}