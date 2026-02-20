#include <bits/stdc++.h>

using namespace std;

int n;
int dp[50001];

int main() {
    cin >> n;

    dp[1] = 1;
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 1; i + j * j <= n; j++) {
            if(dp[i + j * j] == 0) {
                dp[i + j * j] = dp[i] + 1;
            } else {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
    }

    cout << dp[n];
}