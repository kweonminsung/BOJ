#include <bits/stdc++.h>

using namespace std;

int N, s, w;
vector<pair<int, int>> sw;
int ans = 0;

void func(int hold) {
  if (hold > N)
    return;

  for (int i = 0; i < sw.size(); i++) {
    if (sw[hold].first <= 0) {
      func(hold + 1);
      continue;
    }
    if (hold == i || sw[i].first <= 0)
      continue;

    sw[hold].first -= sw[i].second;
    sw[i].first -= sw[hold].second;
    func(hold + 1);
    sw[hold].first += sw[i].second;
    sw[i].first += sw[hold].second;
  }

  int broke = 0;
  for (auto i : sw)
    if (i.first <= 0)
      broke++;
  ans = max(ans, broke);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> s >> w;
    sw.push_back({s, w});
  }
  func(0);

  cout << ans;
}
