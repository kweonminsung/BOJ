#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n;
int arr[MAX], dp[MAX][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  dp[1][1] = arr[1];
  dp[2][1] = arr[2];
  dp[2][2] = arr[1] + arr[2];

  for (int i = 3; i <= n; i++) {
    dp[i][1] = max(max(arr[i] + dp[i - 2][1], arr[i] + dp[i - 2][2]),
                   max(arr[i] + dp[i - 3][1], arr[i] + dp[i - 3][2]));
    dp[i][2] = arr[i] + dp[i - 1][1];
  }

  cout << max(max(dp[n][1], dp[n][2]), max(dp[n - 1][1], dp[n - 1][2]));
}
