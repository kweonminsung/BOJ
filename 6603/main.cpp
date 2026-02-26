#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n != 0) {
        vector<int> V;
        for(int i = 0; i < n; i++) {
            int ipt;
            cin >> ipt;
            V.push_back(ipt);
        }

        vector<int> order;
        for(int i = 0; i < 6; i++) {
            order.push_back(1);
        }
        for(int i = 0; i < n - 6; i++) {
            order.push_back(0);
        }

        do {
            for(int i = 0; i < n; i++) {
                if(order[i] == 1) cout << V[i] << " ";
            }
            cout << "\n";
        } while(prev_permutation(order.begin(), order.end()));
        cout << "\n";
        cin >> n;
    }
}