#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  } else
    return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, b;
  cin >> n >> m >> b;
  vector<int> V;
  vector<pair<int, int>> result;

  for (int i = 0; i < n * m; i++) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  sort(V.begin(), V.end());

  for (int i = V.front(); i <= V.back(); i++) {
    int time = 0, tempB = b;

    for (int j = 0; j < n * m; j++) {
      time += (i > V[j] ? i - V[j] : 2 * (V[j] - i));
      tempB += V[j] - i;
    }

    if (tempB < 0)
      continue;
    result.push_back({time, i});
  }

  sort(result.begin(), result.end(), cmp);

  cout << result.front().first << " " << result.front().second;
}
