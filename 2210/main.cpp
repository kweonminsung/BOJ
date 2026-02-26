#include <bits/stdc++.h>

using namespace std;

int board[6][6];
int str[6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
set<int> rst;

void func(int k, int x, int y) {
    if(k == 5) {
        // cout << 100000 * str[0] + 10000 * str[1] + 1000 * str[2] + 100 * str[3] + 10 * str[4] + str[5] << " ";
        rst.insert(100000 * str[0] + 10000 * str[1] + 1000 * str[2] + 100 * str[3] + 10 * str[4] + str[5]);
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir]; int ny = y + dy[dir];

        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

        str[k + 1] = board[nx][ny];
        func(k + 1, nx, ny);
    }
}

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            
            str[0] = board[i][j];
            func(0, i, j);
        }
    }

    // for(auto x : rst) {
    //     cout << x << "\n";
    // }
    
    cout << rst.size();
}