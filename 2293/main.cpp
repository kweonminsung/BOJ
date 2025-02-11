#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

int n, k;
int arr[MAX];
int dp[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = arr[i]; j <= k; j++) {
      dp[j] = dp[j] + dp[j - arr[i]];
    }
  }

  cout << dp[k];
}
