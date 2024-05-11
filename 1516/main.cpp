#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> adj[501];
int deg[501];
int buildT[501];
int buildA[501];

queue<int> q;
vector<int> result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    int t, pre;

    cin >> t;
    buildT[i] = t;
    buildA[i] = t;

    while (true) {
      cin >> pre;
      if (pre == -1)
        break;

      adj[pre].push_back(i);
      deg[i]++;
    }
  }

  for (int i = 1; i <= N; i++)
    if (deg[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      deg[nxt]--;
      buildA[nxt] = max(buildA[nxt], buildA[cur] + buildT[nxt]);
      if (deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  for (int i = 1; i <= N; i++)
    cout << buildA[i] << "\n";
}
