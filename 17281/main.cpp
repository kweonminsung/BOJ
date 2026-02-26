#include <bits/stdc++.h>

using namespace std;

int n;
int inning[51][10];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> inning[i][j];
        }
    }

    vector<int> order;
    for(int i = 1; i < 9; i++) {
        order.push_back(i);
    }

    int maxN = 0;

    do {
        vector<int> realOrder;
        realOrder = order;
        realOrder.insert(realOrder.begin() + 3, 0);
        
        int outs = 0, curTurn = 0, curInning = 0, rst = 0;
        bool base[4] = {false, false, false, false};

        while(curInning < n) {
            int roundRst = inning[curInning][realOrder[curTurn]];

            if(roundRst == 0) {
                if(outs + 1 == 3) {
                    outs = 0;
                    curInning++;
                    fill(base, base + 4, false);
                } else {
                    outs++;
                }
            } else {
                for(int i = 3; i >= 1; i--) {
                    if(base[i]) {
                        base[i] = false;
                        if(i + roundRst > 3) {
                            rst++;
                        } else {
                            base[i + roundRst] = true;
                        }
                    }
                }
                if(roundRst > 3) {
                    rst++;
                } else {
                    base[roundRst] = true;
                }
            }

            curTurn = (curTurn + 1) % 9;
        }

        maxN = max(maxN, rst);
        // for(auto x : realOrder) {
        //     cout << x << " ";
        // }
        // cout << "\n";
    } while(next_permutation(order.begin(), order.end()));

    cout << maxN;
}