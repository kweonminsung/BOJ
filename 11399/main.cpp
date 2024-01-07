#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, tot = 0;
  cin >> n;
  vector<int> V;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  sort(V.begin(), V.end(), greater<>());

  for (int i = 0; i < n; i++) {
    tot += (i + 1) * V[i];
  }

  cout << tot;
}
