#include <bits/stdc++.h>
#define MAX1 101
#define MAX2 100001

using namespace std;

int N, K, W, V;
int arrW[MAX1], arrV[MAX1];
int dp[MAX2][MAX1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 1; i <= N; i++)
    cin >> arrW[i] >> arrV[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      if (j < arrW[i]) {
        dp[j][i] = dp[j][i - 1];
        continue;
      }
      dp[j][i] = max(dp[j][i - 1], dp[j - arrW[i]][i - 1] + arrV[i]);
    }
  }

  cout << dp[K][N];
}