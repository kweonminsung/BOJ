#include <bits/stdc++.h>

using namespace std;

int n, s, cnt = 0;
int input[20];
int result[20];

void func(int k) {
  if (k == n) {
    return;
  }

  result[k] = result[k - 1];
  func(k + 1);
  if (k == 0)
    result[k] = input[k];
  else
    result[k] = result[k - 1] + input[k];

  if (result[k] == s)
    cnt++;
  func(k + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  for (int i = 0; i < n; i++)
    cin >> input[i];

  func(0);

  cout << cnt;
}
