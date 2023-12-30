#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  map<int, int> M;

  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    M[input] = 1;
  }

  cin >> m;
  while (m--) {
    int input;
    cin >> input;
    if (M[input] == 1)
      cout << 1 << "\n";
    else
      cout << 0 << "\n";
  }
}
