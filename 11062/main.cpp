#include <bits/stdc++.h>

using namespace std;

int t, n;
int arr[1001];
int dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            int ipt;
            cin >> ipt;
            arr[j] = ipt;
            dp[j][j] = ipt;
        }

        for(int j = 2; j <= n; j++) {
            for(int k = 0; k < n - j + 1; k++) {
                int start = k, end = k + j - 1;

                dp[start][end] = max(arr[start] - dp[start + 1][end], arr[end] - dp[start][end - 1]);
            }
        }
        
        int sum = accumulate(arr, arr + n, 0);

        cout << (dp[0][n - 1] + sum) / 2 << "\n";
    }
}