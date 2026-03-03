#include <bits/stdc++.h>

using namespace std;

int n;
int board[21][21];
bool like[401][401];
vector<int> order;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin >> n;
    for(int i = 1; i <= n * n; i++) {
        int ipt1, ipt2;
        cin >> ipt1 >> ipt2;
        order.push_back(ipt1);
        like[ipt1][ipt2] = true;
        cin >> ipt2;
        like[ipt1][ipt2] = true;
        cin >> ipt2;
        like[ipt1][ipt2] = true;
        cin >> ipt2;
        like[ipt1][ipt2] = true;
    }

    for(int x : order) {
        pair<int, int> candid = {-1, -1};
        int candidNum1 = -1, candidNum2 = -1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j] != 0) continue;

                int num1 = 0, num2 = 0;

                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir], ny = j + dy[dir];

                    if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

                    if(board[nx][ny] == 0) num2++;
                    else if(like[x][board[nx][ny]]) num1++;
                }

                if(candidNum1 == -1 || (candidNum1 < num1 || (candidNum1 == num1 && candidNum2 < num2))) {
                    candidNum1 = num1;
                    candidNum2 = num2;
                    candid = {i, j};
                }
            }
        }
        // cout << candid.first << " " << candid.second << " " << candidNum1 << " " << candidNum2 << "\n";
        board[candid.first][candid.second] = x;
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int rst = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir], ny = j + dy[dir];

                if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

                if(board[nx][ny] != 0 && like[board[i][j]][board[nx][ny]]) cnt++;
            }
            rst += (cnt == 0 ? 0 : pow(10, cnt - 1));
        }
    }
    cout << rst;
}