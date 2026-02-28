#include <bits/stdc++.h>

using namespace std;

int n, k;
int medal[1001][3];

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int cnt, g, s, b;
        cin >> cnt >> g >> s >> b;
        medal[cnt][0] = g;
        medal[cnt][1] = s;
        medal[cnt][2] = b;
    }

    int order = 1;
    for(int i = 1; i <= n; i++) {
        if(i == k) continue;
        bool isLost = false;

        // gold
        if(medal[i][0] > medal[k][0]) {
            isLost = true;
        } else if(medal[i][0] == medal[k][0]) {
            // silver
            if(medal[i][1] > medal[k][1]) {
                isLost = true;
            } else if(medal[i][1] == medal[k][1]) {
                // bronze
                if(medal[i][2] > medal[k][2]) {
                    isLost = true;
                }
            }
        }

        if(isLost) order++;
    }

    cout << order;
}