#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> m;

        unordered_map<string, int> M;
        set<string> S;
        
        for(int j = 0; j < m; j++) {
            string ipt1, ipt2;
            cin >> ipt1 >> ipt2;

            M[ipt2]++;
            S.insert(ipt2);
        }

        int rst = 1;
        for(auto x : S) {
            rst *= (M[x] + 1);
        }
        cout << (rst - 1) << "\n";
    }
}