#include <bits/stdc++.h>
#define DIV 1000000009

using namespace std;
using ll = long long;

int t;
int dp[1000001];

int main() {
    cin >> t;

    vector<int> V;
    int maxN = 0;
    for(int i = 0; i < t; i++) {
        int ipt;
        cin >> ipt;
        V.push_back(ipt);
        maxN = max(maxN, ipt);
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= maxN; i++) {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % DIV + dp[i - 3]) % DIV;
    }

    for(int x : V) {
        cout << dp[x] << "\n";
    }
}