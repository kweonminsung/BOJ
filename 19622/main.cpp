#include <bits/stdc++.h>

using namespace std;

int n;
int meet[100001][3];
int dp[100001];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int from, to, t;
        cin >> from >> to >> t;
        meet[i][0] = from;
        meet[i][1] = to - 10;
        meet[i][2] = t;
    }

    dp[0] = 0;
    dp[1] = meet[1][2];
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + meet[i][2]);
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }

    cout << dp[n];

}