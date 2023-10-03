#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int h, m;
    cin >> h >> m;

    int addh, addm;
    cin >> addm;
    addh = addm / 60;
    addm %= 60;

    if(m + addm >= 60) {
        if(h + addh + 1 >= 24) h -= 24;
        cout << h + addh + 1 << " " << m + addm - 60;
    }
    else {
        if(h + addh >= 24) h -= 24;
        cout << h + addh << " " << m + addm;
    }
}
