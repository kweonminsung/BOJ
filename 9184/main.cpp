#include <bits/stdc++.h>

using namespace std;

int M[21][21][21];

int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;

  if (a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);

  if (M[a][b][c] != 0)
    return M[a][b][c];

  if (a < b && b < c) {
    M[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return M[a][b][c];
  }

  else {
    M[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                 w(a - 1, b - 1, c - 1);
    return M[a][b][c];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++) {
      for (int u = 1; u <= 20; u++) {
        w(i, j, u);
      }
    }
  }

  while (a != -1 || b != -1 || c != -1) {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";

    cin >> a >> b >> c;
  }
}
