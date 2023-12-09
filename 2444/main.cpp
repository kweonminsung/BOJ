#include <bits/stdc++.h>

using namespace std;

void print(char c, int n) {
    while(n--) cout << c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        print(' ', n - i);
        print('*', 2 * i -1);
        cout << "\n";
    }
    for(int i = n - 1; i >= 1; i--) {
        print(' ', n - i);
        print('*', 2 * i -1);
        cout << "\n";
    }
}
