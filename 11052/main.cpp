#include <bits/stdc++.h>
#define MAX 1002

using namespace std;

int N;
int arr[MAX], dp[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j++) {
      dp[j] = max(dp[j], dp[j - i] + arr[i]);
    }
  }
  cout << dp[N];
}
