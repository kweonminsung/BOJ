#include <bits/stdc++.h>

using namespace std;

int n, maxN = 0;
int board[6][21][21];
int tempBoard[21][21];

void copyBoard(int from[21][21], int to[21][21]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            to[i][j] = from[i][j];
        }
    }
}

void moveBoard(int dir, int curB[21][21]) {
    for(int i = 0; i < n; i++) {
        fill(tempBoard[i], tempBoard[i] + n, 0);
    }

    if(dir == 0) { // left
        for(int i = 0; i < n; i++) {
            int preI = -1, preV, cur = 0;
            int tempCur = 0;

            while(cur < n) {
                if(curB[i][cur] == 0) {
                    cur++;
                    continue;
                }

                if(preI == -1) {
                    preI = cur;
                    preV = curB[i][cur];
                } else if(preV == curB[i][cur]) {
                    tempBoard[i][tempCur] = 2 * preV;
                    tempCur++;
                    preI = -1;
                } else {
                    tempBoard[i][tempCur] = preV;
                    tempCur++;
                    preI = cur;
                    preV = curB[i][cur];
                }
                cur++;
            }
            if(preI != -1) {
                tempBoard[i][tempCur] = preV;
            }
        }
    } else if(dir == 1) { // right
        for(int i = 0; i < n; i++) {
            int preI = -1, preV, cur = n - 1;
            int tempCur = n - 1;

            while(cur >= 0) {
                if(curB[i][cur] == 0) {
                    cur--;
                    continue;
                }

                if(preI == -1) {
                    preI = cur;
                    preV = curB[i][cur];
                } else if(preV == curB[i][cur]) {
                    tempBoard[i][tempCur] = 2 * preV;
                    tempCur--;
                    preI = -1;
                } else {
                    tempBoard[i][tempCur] = preV;
                    tempCur--;
                    preI = cur;
                    preV = curB[i][cur];
                }
                cur--;
            }
            if(preI != -1) {
                tempBoard[i][tempCur] = preV;
            }
        }
    } else if(dir == 2) { // top
        for(int i = 0; i < n; i++) {
            int preI = -1, preV, cur = 0;
            int tempCur = 0;

            while(cur < n) {
                if(curB[cur][i] == 0) {
                    cur++;
                    continue;
                }

                if(preI == -1) {
                    preI = cur;
                    preV = curB[cur][i];
                } else if(preV == curB[cur][i]) {
                    tempBoard[tempCur][i] = 2 * preV;
                    tempCur++;
                    preI = -1;
                } else {
                    tempBoard[tempCur][i] = preV;
                    tempCur++;
                    preI = cur;
                    preV = curB[cur][i];
                }
                cur++;
            }
            if(preI != -1) {
                tempBoard[tempCur][i] = preV;
            }
        }

    } else { // down
        for(int i = 0; i < n; i++) {
            int preI = -1, preV, cur = n - 1;
            int tempCur = n - 1;

            while(cur >= 0) {
                if(curB[cur][i] == 0) {
                    cur--;
                    continue;
                }

                if(preI == -1) {
                    preI = cur;
                    preV = curB[cur][i];
                } else if(preV == curB[cur][i]) {
                    tempBoard[tempCur][i] = 2 * preV;
                    tempCur--;
                    preI = -1;
                } else {
                    tempBoard[tempCur][i] = preV;
                    tempCur--;
                    preI = cur;
                    preV = curB[cur][i];
                }
                cur--;
            }
            if(preI != -1) {
                tempBoard[tempCur][i] = preV;
            }
        }
    }
    copyBoard(tempBoard, curB);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxN = max(maxN, curB[i][j]);
        }
    }
}

void func(int k) {
    if(k == 5) return;
    
    for(int dir = 0; dir < 4; dir++) {
        copyBoard(board[k], board[k + 1]);
        moveBoard(dir, board[k + 1]);
        func(k + 1);
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[0][i][j];
            maxN = max(maxN, board[0][i][j]);
        }
    }

    // moveBoard(3, board[0]);
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << board[0][i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    func(0);

    cout << maxN;
}