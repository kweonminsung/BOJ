#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> words;

char moveChar(char c, int num) {
    return (c - 'a' + num) % 26 + 'a';
}

string moveString(string str, int num) {
    for(char &c: str) {
        c = moveChar(c, num);
    }
    return str;
}

int main() {
    string pass;
    cin >> pass;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }

    int moved = -1;
    for(int mv = 0; mv < 26; mv++) {
        for(int i = 0; i < n; i++) {
            string movedStr = moveString(pass, mv);
            if(movedStr.find(words[i]) != string::npos) {
                moved = mv;
                break;
            }
        }
    }

    cout << moveString(pass, moved);
}