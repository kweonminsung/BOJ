#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k;

int main() {
    cin >> n >> k;

    ll left = 1, right = n * n;

    while(left <= right) {
        ll mid = (left + right) / 2;

        ll cnt = 0;

        for(ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }
        // cout << mid << " " << cnt << "\n";

        if(cnt >= k) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left;
}