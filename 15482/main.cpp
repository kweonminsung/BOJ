#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if(str1.size() < str2.size()) {
        swap(str1, str2);
    }

    int rst = 0;

    dp[0][0] = (str1.substr(0,3) == str2.substr(0,3));
    for(int i = 1; i < str1.size() / 3; i++) {
        if(str1.substr(i * 3, 3) == str2.substr(0, 3))
            dp[i][0] = 1;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for(int j = 1; j < str2.size() / 3; j++) {
        if(str1.substr(0, 3) == str2.substr(j * 3, 3))
            dp[0][j] = 1;
        else
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < str1.size() / 3; i++) {
        for (int j = 1; j < str2.size() / 3; j++) {
            if (str1.substr(i * 3, 3) == str2.substr(j * 3, 3)) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            rst = max(rst, dp[i][j]);
        }
    }

    cout << rst;
}