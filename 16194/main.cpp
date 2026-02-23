#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1002];
int dp[1002];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i] + arr[i]);
        }
        
        // for(int i = 1; i <= n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
    }


    cout << dp[n];
}