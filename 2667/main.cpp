#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n;
string board[30];
int vis[30][30];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }

  int cnt = 0;
  queue<pair<int, int>> Q;
  vector<int> V;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] == 0 && board[i][j] == '1') {
        cnt++;

        int elements = 0;

        Q.push({i, j});
        vis[i][j] = 1;

        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();
          elements++;

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (vis[nx][ny] != 0 || board[nx][ny] == '0')
              continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }

        V.push_back(elements);
      }
    }
  }

  sort(V.begin(), V.end());

  cout << cnt << "\n";
  for (auto i : V)
    cout << i << "\n";
}
