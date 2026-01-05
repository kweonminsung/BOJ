#include <bits/stdc++.h>

using namespace std;

int n = 0;
pair<int, int> arr[15];
pair<int, int> input[15][15];
vector<int> edge[15];
bool vis[15];
int rst[15];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n - 1; i++) {
    int a, b, p, q;
    cin >> a >> b >> p >> q;

    input[a][b] = {p, q};
    input[b][a] = {q, p};
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  queue<int> Q;
  Q.push(0);
  arr[0] = {1, 1};
  vis[0] = true;

  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    // cout << cur << "|" << arr[cur].first << "/" << arr[cur].second << "\n";

    for(int d : edge[cur]) {
      if(vis[d]) continue;

      vis[d] = true;
      arr[d] = {arr[cur].first * input[cur][d].second, arr[cur].second * input[cur][d].first};

      Q.push(d);
    }
  }

  int lc = 1;
  for(int i = 0; i < n; i++)
    lc = lcm(lc, arr[i].second);

  int gc;
  for(int i = 0; i < n; i++) {
    rst[i] = (lc / arr[i].second) * arr[i].first;
    
    if(i == 0)
      gc = rst[i];
    else 
      gc = gcd(gc, rst[i]);
  }
  
  for(int i = 0; i < n; i++)
    cout << rst[i] / gc << " ";
}

