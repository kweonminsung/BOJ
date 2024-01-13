#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int board[101];
  int dist[101];
  int ladder[101];
  cin >> n >> m;

  fill(dist, dist + 101, -1);
  fill(ladder, ladder + 101, 0);

  for (int i = 0; i < n + m; i++) {
    int from, to;
    cin >> from >> to;
    ladder[from] = to;
  }

  queue<int> Q;
  Q.push(1);
  dist[1] = 0;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    if (ladder[cur] != 0) {
      dist[ladder[cur]] = dist[cur];
      Q.push(ladder[cur]);
      continue;
    }

    for (int dir = 1; dir <= 6; dir++) {
      int nx = cur + dir;

      if (nx > 100)
        continue;
      if (dist[nx] != -1) {
        dist[nx] = min(dist[nx], dist[cur] + 1);
        continue;
      }

      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }

  cout << dist[100];
}
