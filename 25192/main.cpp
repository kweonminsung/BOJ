#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int cnt = 0;
  map<string, int> m;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    if (input == "ENTER") {
      m.clear();
    } else {
      if (m[input] == 0) {
        m[input]++;
        cnt++;
      }
    }
  }

  cout << cnt;
}
