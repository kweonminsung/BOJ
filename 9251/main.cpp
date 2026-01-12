#include <bits/stdc++.h>

using namespace std;

string a, b;
int dp[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

    cin >> a >> b;

    dp[1][1] = (a[0] == b[0] ? 1 : 0);

    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            dp[i][j] = max({dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 1 : 0), dp[i][j - 1], dp[i - 1][j]});
            // cout << i << "|" << j << "|" << dp[i][j] << " ";
        }
        // cout << "\n";
        
    }

    cout << dp[a.length()][b.length()];
}
