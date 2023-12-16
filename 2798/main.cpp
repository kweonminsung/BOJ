#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> v(n), per;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n - 3; i++) {
        per.push_back(0);
    }
    per.push_back(1);
    per.push_back(1);
    per.push_back(1);
    
    int result = 0;

    do {
        int total = 0;
        for(int i = 0; i < n; i++) {
            if(per[i] == 1) total += v[i];
        }

        if(total > m) continue;
        if(m - total < m - result) result = total;
    } while(next_permutation(per.begin(), per.end()));

    cout << result;
}
