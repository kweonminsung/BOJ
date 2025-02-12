#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, ans, ansCur;
int arr[MAX], dp[MAX][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  for (int i = 0; i < N; i++) {
    dp[i][0] = 1;
    dp[i][1] = i;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        if (dp[i][0] < dp[j][0] + 1) {
          dp[i][0] = dp[j][0] + 1;
          dp[i][1] = j;
        }
      }
    }

    if (ans < dp[i][0]) {
      ans = dp[i][0];
      ansCur = i;
    }
  }

  vector<int> V;
  int cur = ansCur;
  while (cur != dp[cur][1]) {
    V.push_back(cur);
    cur = dp[cur][1];
  }
  V.push_back(cur);

  cout << ans << "\n";

  auto iter = V.end() - 1;
  while (iter != V.begin()) {
    cout << arr[*iter] << " ";
    iter--;
  }
  cout << arr[*iter];
}