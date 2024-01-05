#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  long long M[101] = {0, 1, 1, 1, 2, 2};

  for (int i = 6; i <= 100; i++) {
    M[i] = M[i - 1] + M[i - 5];
  }

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    cout << M[input] << "\n";
  }
}
