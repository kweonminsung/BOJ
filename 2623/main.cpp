#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> adj[1001];
int deg[1001];
bool vis[1001];

queue<int> q;
vector<int> result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int n, pre = -1, input;
    cin >> n;
    while (n--) {
      cin >> input;
      if (pre == -1) {
        pre = input;
        continue;
      }

      adj[pre].push_back(input);
      deg[input]++;
      pre = input;
    }
  }

  for (int i = 1; i <= N; i++)
    if (deg[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = true;

    result.push_back(cur);

    for (int nxt : adj[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0)
        q.push(nxt);
    }
  }

  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      cout << 0;
      return 0;
    }
  }

  for (int x : result)
    cout << x << "\n";
}
