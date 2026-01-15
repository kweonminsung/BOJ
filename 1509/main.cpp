#include <bits/stdc++.h>

using namespace std;

string str;
bool pDp[2600][2600]; // i~j 의 팰린드롬 여부 저장
int dp[2600]; // i까지의 최대 팰린드롬 분할 수
 

int main() {
    cin >> str;

    int n = str.length();

    for(int i = 1; i <= n; i++)
        pDp[i][i] = true;
    for(int i = 1; i <= n - 1; i++) 
        if(str[i - 1] == str[i]) pDp[i][i + 1] = true;
    for(int len = 3; len <= n; len++) {
        for(int start = 1; start <= n - len + 1; start++) {
            int end = start + len - 1;

            if(str[start - 1] == str[end - 1] && pDp[start + 1][end - 1])
                pDp[start][end] = true;
        }
    }
    
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = i; j <= n; j++)
    //         cout << pDp[i][j] << " ";
    //     cout << "\n";
    // }

    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(pDp[1][i]) {
            dp[i] = 1;
            continue;
        }

        for(int j = 1; j <= i - 1; j++) {
            if(dp[i] != 0)
                dp[i] = min(dp[i], dp[j] + (pDp[j + 1][i] ? 1 : (i - j + 1)));
            else {
                dp[i] = dp[j] + (pDp[j + 1][i] ? 1 : (i - j + 1));
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    cout << dp[n];
}