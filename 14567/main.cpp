#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> adj[1001];
int deg[1001];
int result[1001];

queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    deg[to]++;
  }

  for (int i = 1; i <= N; i++)
    if (deg[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      deg[nxt]--;
      result[nxt] = result[cur] + 1;

      if (deg[nxt] == 0)
        q.push(nxt);
    }
  }

  for (int i = 1; i <= N; i++)
    cout << result[i] + 1 << " ";
}
