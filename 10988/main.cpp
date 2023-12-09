#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str; cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str.at(i) != str.at(str.size() - i -1)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}
