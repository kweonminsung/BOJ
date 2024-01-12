#include <bits/stdc++.h>

using namespace std;

int n, minH = 100, maxH = 1, result = 1;
int arr[102][102];
int vis[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int h) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] > h && vis[i][j] == 0) {
        cnt++;
        queue<pair<int, int>> Q;
        Q.push({i, j});
        vis[i][j] = 1;

        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
              continue;
            if (vis[nx][ny] == 1 || arr[nx][ny] <= h)
              continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      minH = min(minH, arr[i][j]);
      maxH = max(maxH, arr[i][j]);
    }
  }

  for (int h = minH - 1; h <= maxH; h++) {

    for (int i = 0; i < n; i++)
      fill(vis[i], vis[i] + n, 0);

    result = max(bfs(h), result);
  }

  cout << result;
}
