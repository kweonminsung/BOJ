#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, cnt = 0;
  cin >> n;

  for (int i = 1; i * i <= n; i++)
    cnt++;

  cout << cnt;
}
