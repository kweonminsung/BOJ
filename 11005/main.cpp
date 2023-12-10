#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, b;
    deque<char> d;

    cin >> n >> b;

    while(n) {
        d.push_front((n % b) >= 10 ? (n % b) + 'A' - 10: (n % b) + '0');
        n /= b;
    }

    for(char c : d) {
        cout << c;
    }
}
