#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> lis;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int ipt;
        cin >> ipt;

        if(lis.empty()) {
            lis.push_back(ipt);
        } else {
            if(lis.back() < ipt) {
                lis.push_back(ipt);
            } else {
                *lower_bound(lis.begin(), lis.end(), ipt) = ipt;
            }
        }
    }
    cout << lis.size();
}