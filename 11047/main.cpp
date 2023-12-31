#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> V;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  for (int i = V.size() - 1; i >= 0; i--) {
    while (k >= V[i]) {
      k -= V[i];
      cnt++;
    }
  }

  cout << cnt;
}
