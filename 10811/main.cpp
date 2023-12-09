#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int arr[100] = {0, };

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    while(m--) {
        int i, j;
        cin >> i >> j;
        for(int a = i - 1; a < (i + j) / 2; a++) {
            swap(arr[a], arr[j + i - a - 2]);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
