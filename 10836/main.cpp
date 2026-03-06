#include <bits/stdc++.h>

using namespace std;

int m, n;
int arr[2001];
int grow[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        int zero, one, two;
        cin >> zero >> one >> two;

        grow[zero]++;
        grow[zero + one]++;
    }

    for(int i = 1; i < 2 * m - 1; i++) {
        grow[i] = grow[i - 1] + grow[i];
    }


    for(int i = 0; i < m; i++) {
        cout << grow[m - i - 1] + 1 << " ";
        for(int j = 1; j < m; j++) {
            cout << grow[m - 1 + j] + 1 << " ";
        }
        cout << "\n";
    }
}

