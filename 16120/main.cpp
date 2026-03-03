#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> S;
    for(char c : str) {
        S.push(c);

        if(S.size() >= 4) {
            int a, b, c, d;

            a = S.top();
            S.pop();
            if(a != 'P') {
                S.push(a);
                continue;
            }

            b = S.top();
            S.pop();
            if(b != 'A') {
                S.push(b);
                S.push(a);
                continue;
            }

            c = S.top();
            S.pop();
            if(c != 'P') {
                S.push(c);
                S.push(b);
                S.push(a);
                continue;
            }

            d = S.top();
            S.pop();
            if(d != 'P') {
                S.push(d);
                S.push(c);
                S.push(b);
                S.push(a);
                continue;
            }

            S.push('P');
        }
    }
    
    if(S.size() == 1 && S.top() == 'P') {
        cout << "PPAP";
        return 0;
    }

    if(S.size() == 4) {
        int a, b, c, d;
        a = S.top();
        S.pop();
        b = S.top();
        S.pop();
        c = S.top();
        S.pop();
        d = S.top();
        S.pop();
        if(a == 'P' && b == 'A' && c == 'P' && d == 'P') {
            cout << "PPAP";
            return 0;
        }
    }
    cout << "NP";

    // while(!S.empty()) {
    //     cout << S.top() << " ";
    //     S.pop();
    // }
}