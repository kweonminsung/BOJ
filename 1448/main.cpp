#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> V;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int ipt; cin >> ipt;
        V.push_back(ipt);
    }

    sort(V.begin(), V.end(), greater());

    for(int i = 0; i <= n - 3; i++) {
        if(V[i] < V[i + 1] + V[i + 2]) {
            cout << V[i] + V[i + 1] + V[i + 2];
            return 0;
        }
    }
    cout << -1;
}