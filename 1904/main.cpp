#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  unordered_map<int, int> M({{1, 1}, {2, 2}});

  for (int i = 3; i <= n; i++) {
    M[i] = (M[i - 1] + M[i - 2]) % 15746;
  }

  cout << M[n];
}
