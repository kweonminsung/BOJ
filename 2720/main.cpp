#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int c, t;
    cin >> c;
    t = c / 25;
    cout << t << " ";
    c -= t * 25;
    t = c / 10;
    cout << t << " ";
    c -= t * 10;
    t = c / 5;
    cout << t << " ";
    c -= t * 5;
    cout << c << "\n";
  }
}
