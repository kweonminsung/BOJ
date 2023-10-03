#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int q;
    cin >> q;
    
    while(q--) {
        bool result = true;
        string s;
        cin >> s;

        stack<char> S;

        for(auto c : s) {
            if(c == '(') S.push('(');
            else {
                if(S.empty()) {
                    result = false;
                    break;
                }
                else S.pop();
            }
        }
        cout << (S.empty() && result ? "YES\n" : "NO\n");
    }
}
