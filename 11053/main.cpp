#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, ans = 0;
int arr[MAX], dp[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  fill(dp, dp + MAX, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]);
  }

  cout << ans;
}