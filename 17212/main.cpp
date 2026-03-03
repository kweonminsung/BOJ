#include <bits/stdc++.h>

using namespace std;

int n;
int division[3] = {2, 5, 7};
int dp[100001];

int main() {
    cin >> n;

    for(int i = 0; i <= n; i++)
        dp[i] = i;

    for(int i = 0; i < 3; i++) {
        for(int j = division[i]; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - division[i]] + 1);
        }
    }

    // for(int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";

    cout << dp[n];

}