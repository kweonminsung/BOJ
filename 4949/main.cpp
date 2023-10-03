#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        bool result = true;
        string s;
        getline(cin, s);

        if(s == ".") break;

        stack<char> S;
        for(auto c : s) {
            if(c == '(' || c == '[') S.push(c);
            else if(c == ')') {
                if(S.empty() || S.top() != '(') {
                    result = false;
                    break;
                }
                S.pop();
            }
            else if(c == ']') {
                if(S.empty() || S.top() != '[') {
                    result = false;
                    break;
                }
                S.pop();
            }
        }
        if(s.back() != '.') result = false;
        cout << (S.empty() && result ? "yes\n" : "no\n");
    }
    
}
