#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<ll> V;
vector<ll> twoSums;
vector<ll> twoDiffs;
unordered_map<ll, ll> twoDiffLeft;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll ipt;
        cin >> ipt;
        V.push_back(ipt);
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            twoSums.push_back(V[i] + V[j]);
        }
    }
    sort(twoSums.begin(), twoSums.end());

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            twoDiffs.push_back(V[j] - V[i]);
            twoDiffLeft[V[j] - V[i]] = max(twoDiffLeft[V[j] - V[i]], V[j]);
        }
    }
    sort(twoDiffs.begin(), twoDiffs.end());

    ll maxN = 0;

    for(int x : twoSums) {
        auto [l, r] = equal_range(twoDiffs.begin(), twoDiffs.end(), x);
        if(l == r) continue;

        maxN = max(maxN, twoDiffLeft[twoDiffs[l - twoDiffs.begin()]]);
    }

    cout << maxN;
}