#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int arr[100] = {0, };

    cin >> n >> m;

    while(m--) {
        int i, j, k;
        cin >> i >> j >> k;
        for(int a = i; a <= j; a++) {
            arr[a - 1] = k;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

}
