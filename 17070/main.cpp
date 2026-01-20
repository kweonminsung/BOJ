#include <bits/stdc++.h>

using namespace std;

int n;
int board[20][20];
int dp[20][20];
pair<int, int> prv;

void dfs(int x, int y) {
    // cout << x << "|" << y << "\n";
    // if(x == n - 1 && y == n - 1) {
    //     return;
    // }

    pair<int, int> pprv = prv;
    int nx = x + 1, ny = y + 1;
    if(nx <= n - 1 && ny <= n - 1 && board[x + 1][y + 1] != 1 && board[x + 1][y] != 1 && board[x][y + 1] != 1) {
        dp[nx][ny]++;
        prv = {x, y};
        dfs(nx, ny);
        prv = pprv;
    }

    if(x - pprv.first == 1) {
        nx = x + 1, ny = y;
        if(nx <= n - 1 && ny <= n - 1 && board[nx][ny] != 1) {
            dp[nx][ny]++;
            prv = {x, y};
            dfs(nx, ny);
            prv = pprv;
        }
    }
    if(y - pprv.second == 1) {
        nx = x, ny = y + 1;
        if(nx <= n - 1 && ny <= n - 1 && board[nx][ny] != 1) {
            dp[nx][ny]++;
            prv = {x, y};
            dfs(nx, ny);
            prv = pprv;
        }
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    dp[0][0] = 1, dp[0][1] = 1;
    prv = {0, 0};
    dfs(0, 1);

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }

    cout << dp[n - 1][n - 1];
}
