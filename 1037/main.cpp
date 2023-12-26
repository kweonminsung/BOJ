#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());

  if (v.size() % 2 == 1)
    cout << v[v.size() / 2] * v[v.size() / 2];
  else
    cout << v.front() * v.back();
}
