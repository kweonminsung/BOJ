#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<string, int> M;
set<string> S;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string e = str.substr(find(str.begin(), str.end(), '.') - str.begin() + 1);
        S.insert(e);
        M[e]++;
    }

    for(string str: S) {
        cout << str << " " << M[str] << "\n";
    }
}