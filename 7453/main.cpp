#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll arrA[4001], arrB[4001], arrC[4001], arrD[4001];
vector<ll> V1, V2;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            V1.push_back(arrA[i] + arrB[j]);
            V2.push_back(arrC[i] + arrD[j]);
        }
    }

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());

    ll rst = 0;
    for(auto x : V1) {
        if(!binary_search(V2.begin(), V2.end(), -x)) continue;
        rst += upper_bound(V2.begin(), V2.end(), -x) - lower_bound(V2.begin(), V2.end(), -x);
    }
    
    cout << rst;
}