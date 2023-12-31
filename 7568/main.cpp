#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> V;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    V.push_back({x, y});
  }

  for (int i = 0; i < n; i++) {
    int order = 1;

    for (int j = 0; j < n; j++) {
      if (V[i].first < V[j].first && V[i].second < V[j].second)
        order++;
    }

    cout << order << " ";
  }
}
