#include <bits/stdc++.h>

using namespace std;

int k, n, total = 0;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    
    while (k--)
    {
        cin >> n;
        if(n == 0) {
            total -= S.top();
            S.pop();
        }
        else {
            S.push(n);
            total += n;
        }
    }
    cout << total;
}
