#include <bits/stdc++.h>
#define DIV 1000000009

using namespace std;

int t, n, m;
int maxN;
long long dp[1001][1001];
vector<pair<int, int>> ipt;

int main() {
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        ipt.push_back({n, m});
        maxN = max(maxN, n);
    }

    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    for(int i = 4; i <= maxN; i++) {
        for(int j = floor(i / 3); j <= i; j++) {
            dp[i][j] = (dp[i - 3][j - 1] + dp[i - 2][j - 1] + dp[i - 1][j - 1]) % DIV;
        }
    }
    
    for(int i = 0; i < t; i++) {
        int rst = 0;
        for(int j = 1; j <= ipt[i].second; j++) {
            rst = (rst + dp[ipt[i].first][j]) % DIV;
        }

        cout << rst << "\n";
    }

}