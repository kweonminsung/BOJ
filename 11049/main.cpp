#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> V;
int dp[501][501];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int ipt1, ipt2;
        cin >> ipt1 >> ipt2;

        if(i == 0) V.push_back(ipt1);
        V.push_back(ipt2);
    }

    if(n == 2) {
        cout << V[0] * V[1] * V[2];
    }


    for(int i = 0; i <= V.size() - 3; i++) {
        dp[i][i + 2] = V[i] * V[i + 1] * V[i + 2];
    }

    for(int i = 4; i <= V.size(); i++) {
        for(int j = 0; j <= V.size() - i; j++) {
            int minN = INT_MAX;
            for(int k = j + 1; k <= j + i - 2; k++) {
                minN = min(minN, dp[j][k] + dp[k][j + i - 1] + V[j] * V[k] * V[i + j - 1]);
            }
            dp[j][j + i - 1] = minN;
        }
    }

    // for(int i = 3; i <= V.size(); i++) {
    //     for(int j = 0; j <= V.size() - i; j++) {
    //         cout << dp[j][j + i - 1] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dp[0][V.size() - 1];
}