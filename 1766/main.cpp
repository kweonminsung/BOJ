#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32001];
int deg[32001];

priority_queue<int, vector<int>, greater<int>> q;
vector<int> result;

int n, m;
int from, to;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    adj[from].push_back(to);
    deg[to]++;
  }

  for (int i = 1; i <= n; i++)
    if (deg[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int cur = q.top();
    q.pop();

    result.push_back(cur);
    for (int nxt : adj[cur]) {
      deg[nxt]--;

      if (deg[nxt] == 0)
        q.push(nxt);
    }
  }

  for (int r : result)
    cout << r << " ";
}
