#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;
  vector<int> v;

  for (auto i : str) {
    v.push_back(i - '0');
  }

  sort(v.begin(), v.end());

  for (auto iter = v.rbegin(); iter != v.rend(); iter++) {
    cout << *iter;
  }
}
