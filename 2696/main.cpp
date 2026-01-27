#include <bits/stdc++.h>

using namespace std;

int t, m;

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> m;

        priority_queue<int> lpq;
        priority_queue<int, vector<int>, greater<int>> rpq;

        cout << (m / 2 + 1) << "\n";

        for(int j = 1; j <= m; j++) {
            int ipt;
            cin >> ipt;

            if(lpq.empty()) lpq.push(ipt);
            else {
                if(ipt < lpq.top()) lpq.push(ipt);
                else rpq.push(ipt);
            }

            while(!lpq.empty() && !rpq.empty() && lpq.top() > rpq.top()) {
                rpq.push(lpq.top());
                lpq.pop();
            }

            while(lpq.size() > rpq.size()) {
                rpq.push(lpq.top());
                lpq.pop();
            }
            while(lpq.size() < rpq.size()) {
                lpq.push(rpq.top());
                rpq.pop();
            }

            if(j % 2 == 1) {
                cout << lpq.top() << " ";
            }
            if(j % 20 == 0) cout << "\n";
        }
        cout << "\n";
    }

}