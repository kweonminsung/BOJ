#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string site, pw;
        cin >> site >> pw;

        M[site] = pw;
    }

    while(m--) {
        string site;
        cin >> site;
        cout << M[site] << "\n";
    }
}