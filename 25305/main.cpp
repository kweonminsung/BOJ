#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v.push_back(input);
  }

  sort(v.rbegin(), v.rend());

  cout << v[k - 1];
}
