#include <bits/stdc++.h>

using namespace std;

int n, m, rst;
int board[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool vis[501][501];

void func(int cnt, int x, int y, int tot) {
    if(cnt == 3) {
        rst = max(rst, tot);

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(vis[nx][ny]) continue;

        vis[nx][ny] = true;
        func(cnt + 1, nx, ny, tot + board[nx][ny]);
        vis[nx][ny] = false;
    }
    if(cnt == 2) {
        int prevx, prevy, prevdx, prevdy, pprevx, pprevy;
        for(int i = 0; i < 4; i++) {
            int tx = x - dx[i], ty = y - dy[i];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
            if(vis[tx][ty]) {
                prevx = tx, prevy = ty;
                prevdx = dx[i], prevdy = dy[i];
                break;
            }
        }

        pprevx = prevx - prevdx, pprevy = prevy - prevdy;
        if(pprevx < 0 || pprevx >= n || pprevy < 0 || pprevy >= m || !vis[pprevx][pprevy]) return;

        int nx = prevx + (prevdx == 0 ? -1 : 0), ny = prevy + (prevdy == 0 ? -1 : 0);
        if(!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
            vis[nx][ny] = true;
            func(cnt + 1, nx, ny, tot + board[nx][ny]);
            vis[nx][ny] = false;
        }
        nx = prevx + (prevdx == 0 ? 1 : 0), ny = prevy + (prevdy == 0 ? 1 : 0);
        if(!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
            vis[nx][ny] = true;
            func(cnt + 1, nx, ny, tot + board[nx][ny]);
            vis[nx][ny] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            for(int i = 0; i < n; i++) fill(vis[i], vis[i] + m, false);

            vis[i][j] = true;
            func(0, i, j, board[i][j]);
        }
    }
    
    cout << rst;
}