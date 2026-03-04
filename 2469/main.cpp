#include <bits/stdc++.h>

using namespace std;

int k, n;
char board[1001][27];
int midUpI[27], midDownI[27];
int down[27];
int qY;

int main() {
    cin >> k >> n;

    string want;
    cin >> want;

    for(int i = 0; i < want.length(); i++) {
        down[i] = (int)(want[i] - 'A');
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k - 1; j++) {
            cin >> board[i][j];
            if(board[i][j] == '?') {
                qY = i;
            }
        }
    }

    for(int i = 0; i < k; i++) {
        int curX = i, curY = 0;
        while(curY < qY) {
            if(curX < k - 1 && board[curY][curX] == '-') {
                curX++;
            } else if(curX > 0 && board[curY][curX - 1] == '-') {
                curX--;
            }

            curY++;
        }
        midUpI[curX] = i;
    }

    for(int i = 0; i < k; i++) {
        int curX = i, curY = n - 1;
        while(curY > qY) {
            if(curX < k - 1 && board[curY][curX] == '-') {
                curX++;
            } else if(curX > 0 && board[curY][curX - 1] == '-') {
                curX--;
            }

            curY--;
        }
        midDownI[curX] = down[i];
    }

    // for(int i = 0; i < k; i++) {
    //     cout << midUpI[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < k; i++) {
    //     cout << midDownI[i] << " ";
    // }
    // cout << "\n";

    for(int i = 0; i < k - 1; i++) {
        if(i > 0 && board[qY][i - 1] == '-') {
            board[qY][i] = '*';
            continue;
        }

        if(midUpI[i] == midDownI[i + 1] && midUpI[i + 1] == midDownI[i]) {
            board[qY][i] = '-';
        } else {
            board[qY][i] = '*';
        }
    }

    bool canDo = true;
    for(int i = 0; i < k; i++) {
        if(i < k - 1 && board[qY][i] == '-') {
            if(midUpI[i] != midDownI[i + 1]) canDo = false;
        } else if(i > 0 && board[qY][i - 1] == '-'){
            if(midUpI[i] != midDownI[i - 1]) canDo = false;
        } else {
            if(midUpI[i] != midDownI[i]) canDo = false;
        }
    }

    if(canDo) {
        for(int i = 0; i < k - 1; i++)
            cout << board[qY][i];
    } else {
        for(int i = 0; i < k - 1; i++)
            cout << "x";
    }
}