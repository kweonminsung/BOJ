#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int board[101][101];
int nxt[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    fill(board[i], board[i] + n + 1, INF);

  for (int i = 1; i <= n; i++)
    board[i][i] = 0;

  int a, b, c;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    board[a][b] = min(board[a][b], c);
    nxt[a][b] = b;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (board[i][j] > board[i][k] + board[k][j]) {
          board[i][j] = board[i][k] + board[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (board[i][j] == INF)
        cout << "0 ";
      else
        cout << board[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || board[i][j] == INF) {
        cout << "0\n";
        continue;
      }

      vector<int> path;
      int cur = i;
      while (cur != j) {
        path.push_back(cur);
        cur = nxt[cur][j];
      }
      path.push_back(j);

      cout << path.size() << " ";
      for (int p : path) {
        cout << p << " ";
      }
      cout << "\n";
    }
  }
}
