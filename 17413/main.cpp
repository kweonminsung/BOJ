#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int cur = 0;
    int braketStart = -1, reverseStart = -1;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '<'){
            if(reverseStart != -1) {
                reverse(str.begin() + reverseStart, str.begin() + i);
                cout << str.substr(reverseStart, i - reverseStart);
                reverseStart = -1;
            }

            braketStart = i;
        } else if(str[i] == '>') {
            cout << str.substr(braketStart, i - braketStart + 1);
            braketStart = -1;
        } else if(str[i] == ' ') {
            if(braketStart != -1) continue;

            if(reverseStart != -1) {
                reverse(str.begin() + reverseStart, str.begin() + i);
                cout << str.substr(reverseStart, i - reverseStart);
                reverseStart = -1;
            }
            cout << " ";
        } else {
            if(braketStart == -1 && reverseStart == -1) reverseStart = i;
        }
    }

    if(reverseStart != -1) {
        reverse(str.begin() + reverseStart, str.end());
        cout << str.substr(reverseStart, str.length() - reverseStart);
    }
}
