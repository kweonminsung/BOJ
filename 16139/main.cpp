#include <bits/stdc++.h>

using namespace std;

string s;
int q;
unordered_map<char, vector<int>> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> q;

    for(int i = 0; i < s.length(); i++) {
        M[s[i]].push_back(i);
    }

    for(int i = 0; i < q; i++) {
        char c; int from, to;
        cin >> c >> from >> to;

        cout << upper_bound(M[c].begin(), M[c].end(), to) - lower_bound(M[c].begin(), M[c].end(), from) << "\n";
    }
}