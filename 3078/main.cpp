#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
vector<int> V;
unordered_map<int, ll> M;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        V.push_back(str.length());
    }

    M[V[0]]++;

    ll rst = 0;
    for(int i = 1; i <= k; i++) {
        rst += M[V[i]];
        M[V[i]]++;
    }

    for(int i = k + 1; i <= n - 1; i++) {
        M[V[i - k - 1]]--;
        rst += M[V[i]];
        M[V[i]]++;
    }

    cout << rst;
}
