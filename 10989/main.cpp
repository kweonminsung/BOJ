#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, int> m;
  int maxN = 0;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    m[input]++;
    maxN = max(input, maxN);
  }

  for (int i = 1; i <= maxN; i++) {
    for (int j = 0; j < m[i]; j++)
      cout << i << "\n";
  }
}
