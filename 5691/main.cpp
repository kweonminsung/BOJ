#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    while(a != 0 && b != 0) {
        int a1 = min(a, b), b1 = max(a, b);
        cout << a1 - (b1 - a1) << "\n";
        
        cin >> a >> b;
    }
}