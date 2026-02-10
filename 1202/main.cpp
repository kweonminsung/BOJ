#include <bits/stdc++.h>

using namespace std;
using p = pair<int, int>;
using ll = long long;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    priority_queue<p, vector<p>, greater<p>> pq;

    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        pq.push({m, v});
    }

    vector<int> C;
    for(int i = 0; i < k; i++) {
        int ipt;
        cin >> ipt;
        C.push_back(ipt);
    }
    sort(C.begin(), C.end());

    priority_queue<int> valuePQ;

    ll rst = 0;
    for(auto x : C) {
        while(!pq.empty() && pq.top().first <= x) {
            valuePQ.push(pq.top().second);
            pq.pop();
        }

        if(!valuePQ.empty()) {
            rst += valuePQ.top();
            valuePQ.pop();
        }   
    }
    cout << rst;
}