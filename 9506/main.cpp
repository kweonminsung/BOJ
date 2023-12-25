#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    int n, total = 0;
    cin >> n;

    if (n == -1)
      return 0;

    vector<int> v;
    for (int i = 1; i < n; i++) {
      if (n % i == 0) {
        v.push_back(i);
        total += i;
      }
    }
    if (total == n) {
      cout << n << " = ";
      for (int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " + ";
      }
      cout << v.back() << "\n";
    } else {
      cout << n << " is NOT perfect.\n";
    }
  }
}
