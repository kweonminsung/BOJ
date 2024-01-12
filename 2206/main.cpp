#include <bits/stdc++.h>

using namespace std;

int n, m, result = -1;
string arr[1002];
int dist1[1002][1002];
int dist2[1002][1002];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    fill(dist1[i], dist1[i] + m, -1);
    fill(dist2[i], dist2[i] + m, -1);
  }

  queue<pair<int, int>> Q;

  Q.push({0, 0});
  dist1[0][0] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dist1[nx][ny] != -1 || arr[nx][ny] == '1')
        continue;

      dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  Q.push({n - 1, m - 1});
  dist2[n - 1][m - 1] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dist2[nx][ny] != -1 || arr[nx][ny] == '1')
        continue;

      dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }

  int result = INT_MAX;

  if (dist2[0][0] != -1)
    result = dist2[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0)
        continue;

      int min_dist1 = INT_MAX, min_dist2 = INT_MAX;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (dist1[nx][ny] != -1)
          min_dist1 = min(min_dist1, dist1[nx][ny]);
        if (dist2[nx][ny] != -1)
          min_dist2 = min(min_dist2, dist2[nx][ny]);
      }
      if (min_dist1 != INT_MAX && min_dist2 != INT_MAX)
        result = min(result, min_dist1 + min_dist2 + 1);
    }
  }

  if (result == INT_MAX)
    cout << -1;
  else
    cout << result;
}
