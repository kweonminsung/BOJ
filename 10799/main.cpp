#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int cnt = 0;

  stack<char> S;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      cnt++;
      S.push(s[i]);
    } else {
      if (S.top() == '(') {
        if (s[i - 1] == '(') {
          S.pop();
          cnt += S.size() - 1;
          continue;
        }
        S.pop();
        continue;
      }

      S.push(s[i]);
    }
  }

  cout << cnt;
}
