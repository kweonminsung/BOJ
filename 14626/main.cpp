#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int tot = 0, n = 0;
    for(int i = 0; i < str.length() - 1; i++) {
        if('0' <= str[i] && str[i] <= '9') {
            tot += ((i % 2 == 0) ? 1 : 3) * (str[i] - '0');
        } else {
            n = i;
        }
    }

    int tmp = 10 - (str[str.length() - 1] - '0');
    
    if(n % 2 == 0) {
        cout << (tmp - (tot % 10) + 10) % 10;
    } else {
        int rst = 0;
        while(((tmp - (tot % 10)) % 10 + 10 * rst) % 3 != 0) rst++;
        cout << (((tmp - (tot % 10)) % 10 + 10 * rst) / 3 + 10) % 10;
    }
}
