#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[1001][1001];
bool vis[1001][1001];
pair<int, int> startFrom[1001][1001];

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            startFrom[i][j] = {-1, -1};
        }
    }

    int rst = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;

            bool busted = false;
            pair<int, int> cur = {i, j};
            while(!vis[cur.first][cur.second]) {
                // cout << cur.first << " " << cur.second << "\n";

                vis[cur.first][cur.second] = true;
                startFrom[cur.first][cur.second] = {i, j};

                switch(board[cur.first][cur.second]) {
                    case 'D':
                        cur.first++;
                        break;
                    case 'U':
                        cur.first--;
                        break;
                    case 'L':
                        cur.second--;
                        break;
                    case 'R':
                        cur.second++;
                        break;
                }

                if(startFrom[cur.first][cur.second] != make_pair(-1, -1) && startFrom[cur.first][cur.second] != make_pair(i, j)) {
                    busted = true;
                    break;
                }
            }
            if(!busted)
                rst++;
        }
    }

    cout << rst;
}