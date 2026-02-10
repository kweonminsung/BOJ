#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> V;
        for(int j = 0; j < n; j++) {
            string str;
            cin >> str;
            V.push_back(str);
        }
        sort(V.begin(), V.end());

        bool isGood = true;
        for(int j = 0; j < n - 1; j++) {
            if(!V[j].compare(V[j + 1].substr(0, V[j].length()))) {
                isGood = false;
                break;
            }
        }

        cout << (isGood ? "YES" : "NO") << " \n";
    }
}