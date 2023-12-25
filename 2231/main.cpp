#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> v;

  for (int i = 1; i < n; i++) {
    int temp = i;
    int total = i;

    while (temp) {
      total += temp % 10;
      temp /= 10;
    }

    if (total == n)
      v.push_back(i);
  }

  if (v.size() == 0)
    cout << 0;
  else
    cout << *min_element(v.begin(), v.end());
}
