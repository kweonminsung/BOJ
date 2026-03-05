#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1001][3];
int dp[3][1001][3];

int main() {
    cin >> n;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j][0] = 1e9;
            dp[i][j][1] = 1e9;
            dp[i][j][2] = 1e9;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    dp[0][0][0] = cost[0][0];
    dp[1][0][1] = cost[0][1];
    dp[2][0][2] = cost[0][2];

    for(int i = 1; i < n - 1; i++) {
        for(int j = 0; j < 3; j++) {
            dp[j][i][0] = min(dp[j][i - 1][1], dp[j][i - 1][2]) + cost[i][0];
            dp[j][i][1] = min(dp[j][i - 1][0], dp[j][i - 1][2]) + cost[i][1];
            dp[j][i][2] = min(dp[j][i - 1][0], dp[j][i - 1][1]) + cost[i][2];
        }
    }

    vector<int> rst;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(j == k || i == k) continue;
                rst.push_back(dp[i][n - 2][j] + cost[n - 1][k]);
            }
        }
    }

    // for(auto x : rst) {
    //     cout << x << " ";
    // }

    cout << *min_element(rst.begin(), rst.end());
}