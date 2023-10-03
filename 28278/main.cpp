#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;

    stack<int> S;

    while(q--) {
        int op;
        cin >> op;

        if(op == 1) {
            int add;
            cin >> add;
            S.push(add);
        } else if(op == 2) {
            if(S.empty()) cout << "-1\n";
            else {
                cout << S.top() << "\n";
                S.pop();
            }
        } else if(op == 3) {
            cout << S.size() << "\n";
        } else if(op == 4) {
            if(S.empty()) cout << "1\n";
            else cout << "0\n";
        } else if(op == 5) {
            if(S.empty()) cout << "-1\n";
            else cout << S.top() << "\n";
        }
    }
}
