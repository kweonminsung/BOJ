#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, test;
    cin >> str >> test;

    int testSize = test.size();

    deque<char> D;

    for(int i = 0; i < str.length(); i++) {
        D.push_back(str[i]);
        if(str[i] == test.back()) {
            if(D.size() < testSize) continue;

            bool flag = true;
            for(int i = D.size() - 1, j = testSize - 1; j >= 0; i--, j--) {
                if (D[i] != test[j]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;


            int temp = testSize;
            while (temp--) D.pop_back();
        }
    }

    if(!D.size()) cout << "FRULA";
    else
        for(char c : D) cout << c;
}