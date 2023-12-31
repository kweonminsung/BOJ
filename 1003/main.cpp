#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> F({
    {-1, 1},
    {0, 0},
    {1, 1},
});

int fibonacci(int n) {
  if (n == 0 || n == 1 || n == -1) {
    return F[n];
  } else {
    if (F[n] != 0)
      return F[n];
    F[n] = fibonacci(n - 1) + fibonacci(n - 2);
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

    cout << fibonacci(input - 1) << " " << fibonacci(input) << "\n";
  }
}
