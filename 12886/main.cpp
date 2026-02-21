#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int vis[2000][2000];

int main() {
    cin >> a >> b >> c;

    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(a, b, c));

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int first = get<0>(cur), second = get<1>(cur), third = get<2>(cur);
        if(vis[first][second]) continue;
        vis[first][second] = true;

        if(first == second && second == third) {
            cout << 1;
            return 0;
        }

        if(first > second) {
            Q.push(make_tuple(first - second, second * 2, third));
        } else {
            Q.push(make_tuple(first * 2, second - first, third));
        }

        if(first > third) {
            Q.push(make_tuple(first - third, second, third * 2));
        } else {
            Q.push(make_tuple(first * 2, second, third - first));
        }

        if(second > third) {
            Q.push(make_tuple(first, second - third, third * 2));
        } else {
            Q.push(make_tuple(first, second * 2, third - second));
        }
    }

    cout << 0;
}