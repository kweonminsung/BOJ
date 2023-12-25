#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tot = 0;
  vector<int> v;

  for (int i = 0; i < 5; i++) {
    int input;
    cin >> input;
    tot += input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());

  cout << tot / 5 << "\n" << v[2];
}
