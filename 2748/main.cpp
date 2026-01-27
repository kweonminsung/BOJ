#include <bits/stdc++.h>

using namespace std;

long long n;
long long dp[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for(long long i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];
}