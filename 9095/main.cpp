#include <bits/stdc++.h>

using namespace std;

map<int, int> F({{1, 1}, {2, 2}, {3, 4}});

int func(int n) {
  if (n == 1 || n == 2 || n == 3) {
    return F[n];
  } else {
    if (F[n] != 0)
      return F[n];
    F[n] = func(n - 1) + func(n - 2) + func(n - 3);
    return F[n];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;

    cout << func(input) << "\n";
  }
}
