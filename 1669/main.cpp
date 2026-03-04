#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y;

int main() {
    cin >> x >> y;

    if(x == y) {
        cout << 0;
        return 0;
    }

    ll d = y - x, k = sqrt(d);
    if(d == k * k) {
        cout << 2 * k - 1;
    } else if(d <= k * k + k) {
        cout << 2 * k;
    } else {
        cout << 2 * k + 1;
    }
}