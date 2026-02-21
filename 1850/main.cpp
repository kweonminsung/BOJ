#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    string str;
    for(int i = 0; i < gcd(a, b); i++) {
        str += "1";
    }
    cout << str;
}