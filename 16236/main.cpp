#include <bits/stdc++.h>

using namespace std;

int n, fishSize = 2, fishExp = 0, result = 0;
int board[20][20];
int dist[20][20];
pair<int, int> start;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (dist[a.first][a.second] == dist[b.first][b.second]) {
    if (a.first == b.first) {
      return a.second < b.second;
    } else
      return a.first < b.first;
  } else
    return dist[a.first][a.second] < dist[b.first][b.second];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        start = {i, j};
        board[i][j] = 0;
      }
    }
  }

  while (true) {
    for (int i = 0; i < n; i++)
      fill(dist[i], dist[i] + n, -1);

    vector<pair<int, int>> fishToEat;

    queue<pair<int, int>> Q;
    Q.push(start);
    dist[start.first][start.second] = 0;

    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();

      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
          continue;
        if (dist[nx][ny] != -1 || fishSize < board[nx][ny])
          continue;

        if (board[nx][ny] != 0 && fishSize > board[nx][ny]) {
          fishToEat.push_back({nx, ny});
        }

        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        Q.push({nx, ny});
      }
    }

    if (fishToEat.size() == 0)
      break;

    sort(fishToEat.begin(), fishToEat.end(), cmp);

    result += dist[fishToEat[0].first][fishToEat[0].second];

    fishExp++;
    if (fishExp == fishSize) {
      fishSize += 1;
      fishExp = 0;
    }

    start = fishToEat[0];
    board[fishToEat[0].first][fishToEat[0].second] = 0;
  }

  cout << result;
}
