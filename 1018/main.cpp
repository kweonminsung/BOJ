#include <bits/stdc++.h>

using namespace std;

vector<string> V;

int check(int r, int c, char std) {
  char trueStd = std, falseStd = std == 'W' ? 'B' : 'W';
  bool cFlag = true, rFlag = true;

  int cnt = 0;

  for (int i = r; i < r + 8; i++) {
    for (int j = c; j < c + 8; j++) {
      if (V[i][j] != (cFlag ? trueStd : falseStd))
        cnt++;

      cFlag = !cFlag;
    }
    rFlag = !rFlag;
    cFlag = rFlag;
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> cnts;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    V.push_back(str);
  }

  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      cnts.push_back(check(i, j, 'W'));
      cnts.push_back(check(i, j, 'B'));
    }
  }

  sort(cnts.begin(), cnts.end());

  cout << cnts[0];
}
