#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int n = 0, b, digit = 0;

    cin >> str >> b;
    reverse(str.begin(), str.end());

    for(char c : str) {
        n += (c >= 'A' ? (c - 'A' + 10) : (c - '0')) * pow(b, digit);
        digit++;
    }
    
    cout << n;
}
