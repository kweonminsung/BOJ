#include <bits/stdc++.h>

using namespace std;

char board[10][10];
vector<pair<int, int>> V;

bool check(int y, int x) {
    bool have[10] = {0};
    for(int j = 0; j < 9; j++) {
        if(board[y][j] == '0') continue;
        if(have[board[y][j] - '0']) return false;
        have[board[y][j] - '0'] = true;
    }

    fill(have, have + 10, 0);
    for(int j = 0; j < 9; j++) {
        if(board[j][x] == '0') continue;
        if(have[board[j][x] - '0']) return false;
        have[board[j][x] - '0'] = true;
    }

    fill(have, have + 10, 0);
    for(int m = 0; m < 3; m++) {
        for(int n = 0; n < 3; n++) {
            if(board[(y / 3) * 3 + m][(x / 3) * 3 + n]  == '0') continue;
            if(have[board[(y / 3) * 3 + m][(x / 3) * 3 + n] - '0']) return false;
            have[board[(y / 3) * 3 + m][(x / 3) * 3 + n] - '0'] = true;
        }
    }

    return true;
}

void func(int n) {
    if(n == V.size() + 1) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        exit(0);
        return;
    }

    auto cur = V[n - 1];
    if(board[cur.first][cur.second] != '0') {
        func(n + 1);
        return;
    }

    for(int i = 1; i <= 9; i++) {
        board[cur.first][cur.second] = i + '0';
        if(check(cur.first, cur.second)) {
            func(n + 1);
        }
        board[cur.first][cur.second] = '0';
        
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == '0') V.push_back({i, j});
        }
    }

    func(1);
}