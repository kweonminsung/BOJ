#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
vector<pair<int, int>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int start, finish;
  for (int i = 0; i < n; i++) {
    cin >> start >> finish;
    v.push_back({finish, start});
  }

  sort(v.begin(), v.end());

  int lastFinish = -1;
  for (int i = 0; i < n; i++) {
    auto cur = v[i];

    if (lastFinish >= cur.second)
      continue;
    cnt++;
    lastFinish = cur.first - 1;
  }
  cout << cnt;
}
