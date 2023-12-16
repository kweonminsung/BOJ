#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c; cin >> a >> b >> c;

    int minNum = min(a, min(b, c));
    int maxNum = max(a, max(b, c));
    int midNum = a + b + c - minNum - maxNum;

    cout << ((minNum + midNum > maxNum) ? (a + b + c) : (2 * (minNum + midNum) - 1));
}
