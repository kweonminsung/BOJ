#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> V;
int dp[250001]; // i를 마지막으로 할 때 최대 수익

int main() {
    cin >> n;

    while(n != 0) {
        V.clear();
        fill(dp, dp + n, 0);
        for(int i = 0; i < n; i++) {
            int ipt;
            cin >> ipt;
            V.push_back(ipt);
        }

        dp[0] = V[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + V[i], V[i]);
        }

        // for(int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";

        cout << *max_element(dp, dp + n) << "\n";

        cin >> n;
    }
}