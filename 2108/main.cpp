#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int total = 0;
  vector<int> v;
  map<int, int> m;
  set<int> s;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v.push_back(input);
    s.insert(input);
    m[input]++;
    total += input;
  }

  sort(v.begin(), v.end());

  int maxNum = 0;
  for (auto i : s) {
    maxNum = m[i] > maxNum ? m[i] : maxNum;
  }

  vector<int> maxes;
  for (auto i : s) {
    if (m[i] == maxNum)
      maxes.push_back(i);
  }

  sort(maxes.begin(), maxes.end());

  cout << int(round(double(total) / n)) << "\n";
  cout << v[n / 2] << "\n";
  cout << (maxes.size() == 1 ? maxes[0] : maxes[1]) << "\n";
  cout << v[n - 1] - v[0];
}
