#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;
using ll = long long;

ll n;

pair<ll, ll> func(ll num)  {
    if(num == 0) return {0, 1};
    
    auto fnw = func(num / 2);
    ll fn = fnw.first, fnp1 = fnw.second;
    ll f2n = (fn * ((2 * fnp1 % DIV - fn + DIV) % DIV)) % DIV;
    ll f2np1 = (fn * fn % DIV + fnp1 * fnp1 % DIV) % DIV;

    if(num % 2 == 1) {
        return {f2np1, (f2n + f2np1) % DIV};
    } else {
        return {f2n, f2np1};
    }
}

int main() {
    cin >> n;

    cout << func(n).first;
}