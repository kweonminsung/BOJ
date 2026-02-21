#include <bits/stdc++.h>
using namespace std;

int k;
int tree[4000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    int N = (1 << k) - 1;

    int cur = 1;
    while (cur * 2 <= N) cur *= 2;

    for (int cnt = 0; cnt < N; cnt++) {
        int ipt;
        cin >> ipt;
        tree[cur] = ipt;

        if (cur * 2 + 1 <= N) {
            cur = cur * 2 + 1;
            while (cur * 2 <= N) cur *= 2;
        } else {
            while (cur != 1 && (cur % 2 == 1)) cur /= 2;
            if (cur == 1) break;
            cur /= 2;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << tree[i] << " ";
        if (i == 1 || i == 3 || i == 7 || i == 15 || i == 31 || i == 63 || i == 127 || i == 255 || i == 511 || i == 1023) {
            cout << "\n";
        }
    }
}