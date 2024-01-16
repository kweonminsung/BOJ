#include <bits/stdc++.h>

using namespace std;

int m, n, k, cnt = 0;
vector<int> sizes;
int board[100][100];
bool vis[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    for (int j = sy; j < ey; j++) {
      for (int l = sx; l < ex; l++) {
        board[j][l]++;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 && !vis[i][j]) {
        int size = 0;
        queue<pair<int, int>> Q;

        Q.push({i, j});
        vis[i][j] = true;
        cnt++;

        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();
          size++;

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
              continue;
            if (board[nx][ny] != 0 || vis[nx][ny] == true)
              continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
          }
        }
        sizes.push_back(size);
      }
    }
  }

  cout << cnt << "\n";
  sort(sizes.begin(), sizes.end());
  for (int e : sizes)
    cout << e << " ";
}
