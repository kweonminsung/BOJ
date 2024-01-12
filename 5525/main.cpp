#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, cnt = 0;
  string s;
  cin >> n >> m >> s;

  for (int i = 0; i < s.size() - 2; i++) {
    if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
      int oi = 1;
      while (s[i + oi * 2 + 1] == 'O' && s[i + oi * 2 + 2] == 'I') {
        oi++;
      }

      i += oi * 2;

      if (oi >= n) {

        cnt += oi - n + 1;
      }
    }
  }

  cout << cnt;
}
