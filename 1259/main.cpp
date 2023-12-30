#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  cin >> s;
  while (s != "0") {
    bool flag = true;
    for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] != s[s.length() - i - 1]) {
        flag = false;
        break;
      }
    }

    cout << (flag ? "yes" : "no") << "\n";
    cin >> s;
  }
}
