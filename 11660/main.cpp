#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long board[1100][1100];
long long dp[1100][1100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(long long i = 1; i <= n; i++) {
        for(long long j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    dp[1][1] = board[1][1];
    for(long long i = 2; i <= n; i++) {
        dp[1][i] = dp[1][i - 1] + board[1][i];
    }
    for(long long i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + board[i][1];
        for(long long j = 2; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
        }
    }


    // for(long long i = 0; i < n; i++) {
    //     for(long long j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for(long long i = 0; i < m; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << (dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]) << " \n";
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
