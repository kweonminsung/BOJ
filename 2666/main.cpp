#include <bits/stdc++.h>

using namespace std;

int n, k, minN = INT_MAX;
vector<int> order;

void func(int x, int y, pair<int, int> opened) {
    // cout << x << " " << y << " " << opened.first << " " << opened.second << "\n";
    if(x == k) {
        minN = min(minN, y);
        return;
    }

    int ord = order[x];

    if(opened.first == ord || opened.second == ord) {
        func(x + 1, y, opened);
    } else if(ord < opened.first) {
        func(x + 1, y + opened.first - ord, {ord, opened.second});
    } else if(ord > opened.second) {
        func(x + 1, y + ord - opened.second, {opened.first, ord});
    } else {
        func(x + 1, y + ord - opened.first, {ord, opened.second});
        func(x + 1, y + opened.second - ord, {opened.first, ord});
    }
}

int main() {
    cin >> n;
    
    int ipt1, ipt2;
    cin >> ipt1 >> ipt2;

    cin >> k;
    for(int i = 0; i < k; i++) {
        int ipt;
        cin >> ipt;
        order.push_back(ipt - 1);
    }

    func(0, 0, {ipt1 - 1, ipt2 - 1});

    cout << minN;
}