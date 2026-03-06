#include <bits/stdc++.h>

using namespace std;

int n, m, x1_, y1_, x2_, y2_;
char board[301][301];
bool vis[301][301];
vector<pair<int, int>> toBounce;
vector<pair<int, int>> nextBounce;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> x1_ >> y1_ >> x2_ >> y2_;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int rst = 0;
    toBounce.push_back({x1_ - 1, y1_ - 1});
 
    while(true) {
        nextBounce.clear();
        for(auto x : toBounce) {
            if(vis[x.first][x.second]) continue;

            queue<pair<int, int>> Q;
            Q.push(x);
            vis[x.first][x.second] = true;

            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir], ny = cur.second + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny]) continue;

                    if(board[nx][ny] == '1') {
                        nextBounce.push_back({nx, ny});
                        continue;
                    }
                    vis[nx][ny] = true;
                    Q.push({nx, ny});

                    if(board[nx][ny] == '#') {
                        cout << rst + 1;
                        exit(0);
                    }
                }
            }
        }
        
        rst++;         
        toBounce = nextBounce;
    }
}