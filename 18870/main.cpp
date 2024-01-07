#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, int> m;
  set<int> s;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    s.insert(input);
    v.push_back(input);
  }

  int j = 0;
  for (auto i : s) {
    m[i] = j;
    j++;
  }

  for (auto i : v)
    cout << m[i] << " ";
}