#include <bits/stdc++.h>

using namespace std;

int n, m;
int dist[100002];

int dx[2] = {1, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  fill(dist, dist + 100002, -1);

  queue<int> Q;
  Q.push(n);
  dist[n] = 0;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    if (cur != 0) {
      for (int i = cur * 2; i < 100001; i *= 2) {
        dist[i] = dist[i] == -1 ? dist[cur] : min(dist[cur], dist[i]);
        Q.push(i);
      }
    }

    for (int dir = 0; dir < 2; dir++) {
      int nx = cur + dx[dir];

      if (nx < 0 || nx >= 100001)
        continue;
      if (nx == 0) {
        dist[0] = dist[0] == -1 ? dist[cur] + 1 : min(dist[cur] + 1, dist[0]);
        continue;
      }

      if (dist[nx] != -1) {
        dist[nx] = min(dist[nx], dist[cur] + 1);
        continue;
      }

      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  cout << dist[m];
}
