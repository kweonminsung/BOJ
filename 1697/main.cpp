#include <bits/stdc++.h>
#define MAX 100002

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int dist[MAX];
  fill(dist, dist + MAX, -1);

  queue<int> Q;

  Q.push(n);
  dist[n] = 0;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    int nx = cur - 1;
    if (nx >= 0 && nx < MAX && dist[nx] == -1) {
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }

    nx = cur + 1;
    if (nx >= 0 && nx < MAX && dist[nx] == -1) {
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }

    nx = 2 * cur;
    if (nx >= 0 && nx < MAX && dist[nx] == -1) {
      dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }

  cout << dist[k];
}
