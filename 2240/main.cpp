#include <bits/stdc++.h>
#define MAX1 1001
#define MAX2 31

using namespace std;

int t, w, ans = 0;
int arr[MAX1];
int dp[MAX1][MAX2][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t >> w;

  for (int i = 1; i <= t; i++) {
    cin >> arr[i];
  }

  dp[1][0][1] = (arr[1] == 1);
  dp[1][1][2] = (arr[1] == 2);
  ans = max(dp[1][0][1], dp[1][1][2]);

  for (int i = 2; i <= t; i++) {
    dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == 1);

    for (int j = 1; j <= w; j++) {
      if (arr[i] == 1) {
        dp[i][j][1] = max(dp[i - 1][j][1] + 1, dp[i - 1][j - 1][2] + 1);
        dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
      } else {
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
        dp[i][j][2] = max(dp[i - 1][j - 1][1] + 1, dp[i - 1][j][2] + 1);
      }
    }
  }

  for (int i = 1; i <= t; i++) {
    for (int j = 0; j <= w; j++) {
      ans = max({ans, dp[i][j][1], dp[i][j][2]});
    }
  }

  cout << ans;
}
