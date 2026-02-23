#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int board[102][102];
int dist[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> t;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i <= n; i++) {
        fill(dist[i], dist[i] + m + 1, -1);
    }

    queue<pair<int, int>> Q;
    pair<int, int> sword = {-1, -1};
    dist[0][0] = 0;
    Q.push({0, 0});

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(board[nx][ny] == 1) continue;
            if(dist[nx][ny] != -1 && dist[cur.first][cur.second] + 1 >= dist[nx][ny]) continue;

            if(board[nx][ny] == 2) {
                sword = {nx, ny};
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    if(dist[n - 1][m - 1] == -1 && (sword.first == -1 && sword.second == -1)) {
        cout << "Fail";
    } else {
        int rst;

        if(dist[n - 1][m - 1] == -1) {
            rst = dist[sword.first][sword.second] + n - 1 + m - 1 - sword.first - sword.second;
        } else if(sword.first == -1 && sword.second == -1) {
            rst = dist[n - 1][m - 1];
        } else {
            rst = min(dist[n - 1][m - 1], dist[sword.first][sword.second] + n - 1 + m - 1 - sword.first - sword.second);
        }
        
        if(rst > t) {
            cout << "Fail";
        } else {
            cout << rst;
        }
    }

}