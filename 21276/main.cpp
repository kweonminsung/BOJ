#include <bits/stdc++.h>

using namespace std;

int N, M;
unordered_map<string, int> nameNum;
string numName[1001];

vector<int> adj[1001];
int deg[1001];
vector<int> child[1001];
vector<int> father;

queue<int> q;

bool cmp(int a, int b) { return numName[a] < numName[b]; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    string input;
    cin >> input;
    nameNum[input] = i;
    numName[i] = input;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    string from, to;
    cin >> to >> from;
    adj[nameNum[from]].push_back(nameNum[to]);
    deg[nameNum[to]]++;
  }

  for (int i = 1; i <= N; i++)
    if (deg[i] == 0) {
      father.push_back(i);
      q.push(i);
    }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      deg[nxt]--;

      if (deg[nxt] == 0) {
        child[cur].push_back(nxt);
        q.push(nxt);
      }
    }
  }

  sort(father.begin(), father.end(), cmp);

  cout << father.size() << "\n";

  for (int x : father)
    cout << numName[x] << " ";
  cout << "\n";

  vector<int> p;
  for (int i = 1; i <= N; i++)
    p.push_back(i);
  sort(p.begin(), p.end(), cmp);

  for (int x : p) {
    sort(child[x].begin(), child[x].end(), greater<>());

    cout << numName[x] << " " << child[x].size() << " ";
    for (int y : child[x])
      cout << numName[y] << " ";
    cout << "\n";
  }
}
