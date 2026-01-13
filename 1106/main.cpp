#include <bits/stdc++.h>

using namespace std;

int c, n;
int dp[100001];
vector<pair<int, int>> arr;

int main() {
    cin >> c >> n;
    
    fill(dp, dp + 100001, -1);

    int shited = 0;
    for(int i = 0; i < n; i++) {
        int m, p;
        cin >> m >> p;
        arr.push_back({m, p});
        shited = max(shited, (c / p + 1) * p);
        dp[p] = m;
    }
    dp[0] = 0;
    
    sort(arr.begin(), arr.end());

    for(int i = 1; i <= shited; i++) {
        for(int j = 0; j < n; j++) {
            if(i - arr[j].second >= 0) {
                if(dp[i - arr[j].second] != -1) {
                    if(dp[i] == -1) dp[i] = dp[i - arr[j].second] + arr[j].first;
                    else dp[i] = min(dp[i], dp[i - arr[j].second] + arr[j].first);
                }
            }
        }
    }

    // for(int i = 0; i <= shited; i++)
    //     cout << dp[i] << " ";
    
    int rst = INT_MAX;
    for(int i = c; i <= shited; i++)
        if(dp[i] != -1 && rst > dp[i]) rst = dp[i];
    cout << rst;
}