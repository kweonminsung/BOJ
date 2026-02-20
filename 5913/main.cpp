#include <bits/stdc++.h>

using namespace std;

int k, rst;
bool board[6][6];
bool state[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool checkEnd() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(!board[i][j] && !state[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void func(int x1, int y1, int x2, int y2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            bool end = checkEnd();
            if(end) {
                rst++;
                return;
            }
            
            if(x1 == x2 && y1 == y2) {
                return;
            }
        
            int nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[j], ny2 = y2 + dy[j];
            // cout << nx1 << " " << ny1 << "|" << nx2 << " " << ny2 << "\n";

            if(nx1 < 1 || nx1 > 5 || ny1 < 1 || ny1 > 5 || nx2 < 1 || nx2 > 5 || ny2 < 1 || ny2 > 5 
                || board[nx1][ny1] || board[nx2][ny2] || state[nx1][ny1] || state[nx2][ny2]) {
                continue;
            }
            // cout << nx1 << " " << ny1 << "|" << nx2 << " " << ny2 << "\n";
            state[nx1][ny1] = true, state[nx2][ny2] = true;
            func(nx1, ny1, nx2, ny2);
            state[nx1][ny1] = false, state[nx2][ny2] = false;
        }
    }
}

int main() {
    cin >> k;

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = true;
    }

    state[1][1] = true;
    state[5][5] = true;
    func(1, 1, 5, 5);

    cout << rst;
}