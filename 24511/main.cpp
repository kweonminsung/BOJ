#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N;

    vector<int> V(N);
    for(auto& v : V) cin >> v;
    
    deque<int> QS;
    for(auto v : V) {
        int x; cin >> x;
        if(!v) QS.push_back(x);
    }

    cin >> M;
    vector<int> C(M);
    for(auto& c : C) cin >> c;

    for(auto c : C) {
        if(QS.empty()) {
            cout << c << " ";
            continue;
        }
        cout << QS.back() << " ";
        QS.pop_back();
        QS.push_front(c);
    }
}