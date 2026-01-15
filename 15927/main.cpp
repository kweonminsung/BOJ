#include <bits/stdc++.h>

using namespace std;

string str;

bool isPalindrome(string str) {
    for(int i = 0; i < str.length() / 2; i++)
        if(str[i] != str[str.length() - 1 - i]) return false;

    return true;
}

int main() {
    cin >> str;

    if(!isPalindrome(str)) {
        cout << str.length();
        return 0;
    }
    
    bool isAllSame = true;
    for(int i = 1; i <= str.length() - 1; i++) {
        if(str[0] != str[i]) {
            isAllSame = false;
            break;
        }
    }

    cout << (isAllSame ? -1 : (int(str.length()) - 1));
}