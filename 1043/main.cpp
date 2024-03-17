#include <bits/stdc++.h>

using namespace std;

int n, m, knowN, result = 0;
bool know[51];
int teamSize[51];
vector<int> team[51];
vector<int> edge[51];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> knowN;
  for (int i = 0; i < knowN; i++) {
    int input;
    cin >> input;
    know[input] = true;
  }

  for (int i = 0; i < m; i++) {
    cin >> teamSize[i];

    if (teamSize[i] == 0)
      continue;

    for (int j = 0; j < teamSize[i]; j++) {
      int input;
      cin >> input;
      team[i].push_back(input);

      edge[team[i][0]].push_back(input);
      edge[input].push_back(team[i][0]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!know[i])
      continue;

    queue<int> Q;
    Q.push(i);

    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (int nxt : edge[cur]) {
        if (know[nxt])
          continue;

        know[nxt] = true;
        Q.push(nxt);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    if (teamSize[i] == 0)
      result++;
    else if (!know[team[i][0]])
      result++;
  }

  cout << result;
}
