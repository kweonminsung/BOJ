#include <bits/stdc++.h>

using namespace std;

int n, k;
int coin[101];
int dp[10001];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    fill(dp, dp + k + 1, -1);

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j - coin[i] >= 0 && dp[j - coin[i]] != -1) {
                if(dp[j] == -1) {
                    dp[j] = dp[j - coin[i]] + 1;
                } else {
                    dp[j] = min(dp[j], dp[j - coin[i]] + 1);
                }
            }
            // cout << dp[k] << " ";
        }
    }

    // for(int i = 0; i <= k; i++) {
    //     cout << dp[i] << " ";
    // }

    cout << dp[k];
}