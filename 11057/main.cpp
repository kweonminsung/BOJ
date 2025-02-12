#include <bits/stdc++.h>
#define MAX 1001
#define DIV 10007

using namespace std;

int N;
int dp[MAX][11];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= 10; i++)
    dp[1][i] = i;

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= 10; j++) {
      dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % DIV;
    }
  }

  cout << dp[N][10];
}
