#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> S;

    int rst = 0;
    for(char c : str) {
        if(c == '(') {
            S.push('(');
        } else {
            if(S.empty() || S.top() != '(') {
                rst++;
            } else {
                S.pop();
            }
        }
        
    }
    
    rst += S.size();
    cout << rst;
}