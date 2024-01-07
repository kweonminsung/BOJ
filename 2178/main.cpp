#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string arr[102];
  int dis[102][102];

  queue<pair<int, int>> Q;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    fill(dis[i], dis[i] + m, -1);
  }

  dis[0][0] = 1;
  Q.push({0, 0});

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dis[nx][ny] != -1 || arr[nx][ny] == '0')
        continue;

      dis[nx][ny] = dis[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  cout << dis[n - 1][m - 1];
}
