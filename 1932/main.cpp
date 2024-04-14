#include <bits/stdc++.h>

using namespace std;

int n;
int arr[500][500];
int dp[500][500];

int func(int k, int l) {
  if (dp[k][l] == -1) {
    if (l == 0)
      dp[k][l] = func(k - 1, 0) + arr[k][l];
    else if (l == k)
      dp[k][l] = func(k - 1, l - 1) + arr[k][l];
    else
      dp[k][l] = max(func(k - 1, l), func(k - 1, l - 1)) + arr[k][l];
  }

  return dp[k][l];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    fill(dp[i], dp[i] + i + 1, -1);

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      cin >> arr[i][j];

  dp[0][0] = arr[0][0];

  for (int i = 0; i <= n - 1; i++)
    func(n - 1, i);

  cout << *max_element(dp[n - 1], dp[n - 1] + n);
}
