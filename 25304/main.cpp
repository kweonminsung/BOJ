#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int X, N;
  cin >> X >> N;

  int total = 0;
  while (N--) {
    int a, b;
    cin >> a >> b;
    total += a * b;
  }

  cout << (total == X ? "Yes" : "No");
}
