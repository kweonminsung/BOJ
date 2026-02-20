#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char board[601][601];
bool vis[601][601];

int main() {
    cin >> n >> m;

    pair<int, int> start;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'I') {
                start = {i, j};
            }
        }
    }

    int rst = 0;

    queue<pair<int, int>> Q;
    vis[start.first][start.second] = true;
    Q.push(start);

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if(board[nx][ny] == 'X' || vis[nx][ny]) {
                continue;
            }

            if(board[nx][ny] == 'P') rst++;

            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(rst == 0) {
        cout << "TT";
    } else {
        cout << rst;
    }
}