#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[1001][1001];
bool vis[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> bfsStarted[1001][1001];
int bfsCnt[1001][1001];

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] || board[i][j] == '1') continue;

            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({i, j});

            bfsStarted[i][j] = {i, j};
            bfsCnt[i][j] = 1;

            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for(int d = 0; d < 4; d++) {
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if(board[nx][ny] == '1' || vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    Q.push({nx, ny});

                    bfsStarted[nx][ny] = {i, j};
                    bfsCnt[i][j]++;
                }
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         auto bfsInit = bfsStarted[i][j];
    //         cout << bfsCnt[bfsInit.first][bfsInit.second];
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '1') {
                int rst = 1;

                set<pair<int, int>> bfsInitS;

                for(int d = 0; d < 4; d++) {
                    int nx = i  + dx[d], ny = j + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == '1') continue;
                    bfsInitS.insert(bfsStarted[nx][ny]);
                }

                for(auto x : bfsInitS) {
                    rst += bfsCnt[x.first][x.second];
                }

                cout << rst % 10;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
    
}