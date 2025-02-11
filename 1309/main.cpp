#include <bits/stdc++.h>
#define MAX 100001
#define DIV 9901

using namespace std;

int N;
int dp[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  dp[0] = 1;
  dp[1] = 3;

  for (int i = 2; i <= N; i++)
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % DIV;

  cout << dp[N];
}