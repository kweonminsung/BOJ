#include <bits/stdc++.h>

using namespace std;

int t, k;

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> k;

        priority_queue<int, vector<int>, greater<int>> minPQ;
        priority_queue<int, vector<int>, less<int>> maxPQ;
        unordered_map<int, int> M;

        for(int j = 0; j < k; j++) {
            char op;
            int ipt;

            cin >> op >> ipt;

            if(op == 'I') {
                minPQ.push(ipt);
                maxPQ.push(ipt);
                M[ipt]++;
            } else {
                if(ipt == 1) {
                    while(!maxPQ.empty() && M[maxPQ.top()] == 0) {
                        maxPQ.pop();
                    }
                    if(!maxPQ.empty()) {
                        M[maxPQ.top()]--;
                        maxPQ.pop();
                    }
                } else {
                    while(!minPQ.empty() && M[minPQ.top()] == 0) {
                        minPQ.pop();
                    }
                    if(!minPQ.empty()) {    
                        M[minPQ.top()]--;
                        minPQ.pop();
                    }
                }
            }
        }

        while(!maxPQ.empty() && M[maxPQ.top()] == 0) {
            maxPQ.pop();
        }

        if(maxPQ.empty()) {
            cout << "EMPTY\n";
            continue;
        }

        cout << maxPQ.top() << " ";
        while(!minPQ.empty() &&M[minPQ.top()] == 0) {
            minPQ.pop();
        }
        cout << minPQ.top() << "\n";
    }
}