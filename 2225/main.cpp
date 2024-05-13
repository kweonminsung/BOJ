#include <bits/stdc++.h>

using namespace std;

int N, K;

int dp[201][201];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  fill(dp[0] + 1, dp[0] + K + 1, 1);

  for (int i = 1; i <= N - 1; i++)
  {
    for (int j = 1; j <= K; j++)
    {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
    }
  }

  for (int i = 1; i <= K; i++)
    dp[N][i] = (dp[N - 1][i] + dp[N][i - 1]) % 1000000000;

  cout << dp[N][K];
}
