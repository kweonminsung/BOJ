#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n, m;
ll arrA[1001], arrB[1001];
ll preA[1001], preB[1001];
vector<ll> aV, bV;
set<ll> aS;

int main() {
    cin >> t >> n;
    for(int i = 0; i < n; i++) {
        cin >> arrA[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> arrB[i];
    }
    preA[0] = arrA[0], preB[0] = arrB[0];

    for(int i = 1; i < n; i++) {
        preA[i] = preA[i - 1] + arrA[i];
    }
    for(int i = 1; i < m; i++) {
        preB[i] = preB[i - 1] + arrB[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ll sum = (i == 0 ? preA[j] : preA[j] - preA[i - 1]);
            aV.push_back(sum);
            
            aS.insert(sum);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            ll sum = (i == 0 ? preB[j] : preB[j] - preB[i - 1]);
            bV.push_back(sum);
        }
    }

    sort(aV.begin(), aV.end());
    sort(bV.begin(), bV.end());

    ll rst = 0;
    for(int x : aS) {
        ll aCnt = upper_bound(aV.begin(), aV.end(), x) - lower_bound(aV.begin(), aV.end(), x);
        ll bCnt = upper_bound(bV.begin(), bV.end(), t - x) - lower_bound(bV.begin(), bV.end(), t - x);
        rst += (aCnt * bCnt);
    }

    cout << rst;
}