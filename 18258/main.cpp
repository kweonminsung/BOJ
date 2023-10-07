#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
        
    queue<int> Q;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int add;
            cin >> add;
            Q.push(add);
        } else if(op == "pop") {
            if(Q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << Q.front() << "\n";
            Q.pop();
        } else if(op == "front") {
            if(Q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << Q.front() << "\n";
        } else if(op == "back") {
            if(Q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << Q.back() << "\n";
        } else if(op == "size") {
            cout << Q.size() << "\n";
        } else if(op == "empty") {
            cout << (Q.empty() ? 1 : 0) << "\n";
        }
    }
}
