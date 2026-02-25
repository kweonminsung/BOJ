#include <bits/stdc++.h>

using namespace std;

int t, h, w, rst;
char board[101][101];
bool vis[101][101];
queue<pair<int, int>> needKey[27];
bool haveKey[27];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool travel(int x, int y) {
    bool newKeyFound = false;

    if(board[x][y] >= 'A' && board[x][y] <= 'Z' && !haveKey[board[x][y] - 'A']) {
        needKey[board[x][y] - 'A'].push({x, y});
        return newKeyFound;
    }
    if(board[x][y] >= 'a' && board[x][y] <= 'z') {
        if(!haveKey[board[x][y] - 'a']) newKeyFound = true;
        haveKey[board[x][y] - 'a'] = true;
    }
    if(board[x][y] == '$') rst++;

    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir], ny = cur.second + dy[dir];

            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] == '*') continue;
            if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z' && !haveKey[board[nx][ny] - 'A']) {
                needKey[board[nx][ny] - 'A'].push({nx, ny});
                continue;
            }
            if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                if(!haveKey[board[nx][ny] - 'a']) newKeyFound = true;
                haveKey[board[nx][ny] - 'a'] = true;
            }
            if(board[nx][ny] == '$') rst++;

            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    return newKeyFound;
}

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> h >> w;

        // init
        for(int j = 0; j < h; j++) {
            for(int k = 0; k < w; k++) {
                cin >> board[j][k];
            }
        }
        for(int j = 0; j < h; j++) {
            fill(vis[j], vis[j] + w, false);
        }
        for(int j = 0; j < 27; j++) {
            while(!needKey[j].empty()) needKey[j].pop();
        }
        fill(haveKey, haveKey + 27, false);
        rst = 0;

        // get init key
        string keyStr;
        cin >> keyStr;
        if(keyStr != "0") {
            for(char x : keyStr) {
                haveKey[x - 'a'] = true;
            }
        }

        vector<pair<int, int>> entry;
        for(int j = 0; j < w; j++) {
            if(board[0][j] != '*') entry.push_back({0, j});
            if(board[h - 1][j] != '*') entry.push_back({h - 1, j});
        }
        for(int j = 1; j < h - 1; j++) {
            if(board[j][0] != '*') entry.push_back({j, 0});
            if(board[j][w - 1] != '*') entry.push_back({j, w - 1});
        }

        bool newKeyFound = false;
        for(auto ent : entry) {
            if(vis[ent.first][ent.second]) continue;

            if(travel(ent.first, ent.second)) newKeyFound = true;
        }

        // for(int j = 0; j < h; j++) {
        //     for(int k = 0; k < w; k++) {
        //         cout << vis[j][k];
        //     }
        //     cout << "\n";
        // }
        
        while(newKeyFound) {
            bool tmpFound = false;
            for(int j = 0; j < 27; j++) {
                if(haveKey[j]) {
                    while(!needKey[j].empty()) {
                        auto ent = needKey[j].front();
                        needKey[j].pop();
                        // cout << "여기서부터 시작" << ent.first << " " << ent.second << "\n";
                        if(travel(ent.first, ent.second)) tmpFound = true;
                    }
                }
            }
            newKeyFound = tmpFound;
        }

        // for(int j = 0; j < h; j++) {
        //     for(int k = 0; k < w; k++) {
        //         cout << vis[j][k];
        //     }
        //     cout << "\n";
        // }

        cout << rst << "\n";
    }
}