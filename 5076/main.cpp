#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    while(str != "#") {
        stack<string> S;
        bool busted = false;
        int openI = -1;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '<') {
                if(openI != -1) {
                    busted = true;
                    // cout << "shitted1 " << i << " ";
                    break;
                }
                openI = i;
            } else if(str[i] == '>') {
                if(openI == -1) {
                    busted = true;
                    // cout << "shitted2 " << i << " ";
                    break;
                }

                if(i > 0 && str[i - 1] == '/') {
                    openI = -1;
                    continue;
                }

                stringstream ss(str.substr(openI + 1, i - openI - 1));
                string tagWithSlash;
                ss >> tagWithSlash;
                // cout << str.substr(openI + 1, i - openI - 1) << " ";
                if(tagWithSlash[0] == '/') {
                    string tagWithOutSlash = tagWithSlash.substr(1);
                    if(S.empty()) {
                        busted = true;
                        continue;
                    }

                    if(S.top() != tagWithOutSlash) {
                        busted = true;
                        // cout << "shitted3 " << i << " ";
                        break;
                    } else {
                        S.pop();
                    }
                } else {
                    S.push(tagWithSlash);
                }

                openI = -1;
            }
        }

        if(openI != -1 || !S.empty()) {
            busted = true;
            // cout << "shitted4 ";
        }

        if(busted) {
            cout << "illegal\n";
        } else {
            cout << "legal\n";
        }
        getline(cin, str);
    }   
}