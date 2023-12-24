#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    set<long> s;

    while(n--) {
        long input; cin >> input;
        s.insert(input);
    }

    int m; cin >> m;
    vector<long> v;

    while(m--) {
        long input; cin >> input;
        v.push_back(input);
    }

    for(auto i : v) {
        cout << (s.find(i) != s.end() ? 1 : 0) << " ";
    }
}
