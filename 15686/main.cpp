#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[50][50];
vector<pair<int, int>> houses, chickens;
bool usedC[100];
int minN = INT_MAX;

void func(int k, int idx) {
  if (k == m) {
    int result = 0;
    for (int i = 0; i < houses.size(); i++) {
      int chickenPerHouse = INT_MAX;
      for (int j = 0; j < chickens.size(); j++) {
        if (!usedC[j])
          continue;
        chickenPerHouse = min(chickenPerHouse,
                              abs(houses[i].first - chickens[j].first) +
                                  abs(houses[i].second - chickens[j].second));
      }
      result += chickenPerHouse;
    }
    minN = min(minN, result);
    return;
  }

  for (int i = idx; i < chickens.size(); i++) {
    if (usedC[i])
      continue;

    usedC[i] = true;
    func(k + 1, i);
    usedC[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        chickens.push_back({i, j});
      }
      if (board[i][j] == 1) {
        houses.push_back({i, j});
      }
    }
  }

  func(0, 0);

  cout << minN;
}
