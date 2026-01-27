#include <bits/stdc++.h>

using namespace std;

int n;
int arr[65][65];

string func(int x, int y, int size) {
    if(size == 1) {
        return arr[x][y] == 1 ? "1" : "0";
    }

    bool canCompress = true;
    string lu = func(x, y, size / 2);
    string ld = func(x, y + size / 2, size / 2);
    string ru = func(x + size / 2, y, size / 2);
    string rd = func(x + size / 2, y + size / 2, size / 2);

    // cout << x << "|" << y << "|" << size << " " << lu << "|" << ld << "|" << ru << "|" << rd << "\n";
    if((lu == "1" || lu == "0") && (lu == ld && ld == ru && ru == rd)) {
        return lu;
    }
    return "(" + lu + ld + ru + rd + ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << func(0, 0, n);
}