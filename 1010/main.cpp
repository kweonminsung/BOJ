#include <bits/stdc++.h>

using namespace std;

long comb(int n, int k) {
  long num = 1, r = 1;
  for (int i = n; i > n - k; i--) {
    num *= i;
    num /= r++;
  }
  return num;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int n, m;
    cin >> n >> m;

    cout << comb(m, n) << "\n";
  }
}
