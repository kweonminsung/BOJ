#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

int n, k;
int dp[201][201]; // 0~n 까지 k개를 더해서 n이 되는 경우의 수

int main() {
    cin >> n >> k;

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for(int i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            int sum = 0;
            for(int m = 0; m <= i; m++) {
                sum = (sum + dp[m][j - 1]) % MOD;
            }
            dp[i][j] = (dp[i][j] + sum) % MOD;
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= k; j++) {
    //         cout << i << "|" << j << "|" << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[n][k];
}