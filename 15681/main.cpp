#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<int> edge[100001];
int rst[100001];
bool used[100001];

int dfs(int cur) {
    int vertex = 1;
    for(int nx : edge[cur]) {
        if(!used[nx]) {
            used[nx] = true;
            vertex += dfs(nx);
        }
    }

    rst[cur] = vertex;
    // cout << cur << "|" << rst[cur] << " ";
    return vertex;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;

    for(int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }

    used[r] = true;
    dfs(r);

    // for(int i = 1; i <= n; i++) {
    //     cout << rst[i] << " ";
    // }
    // cout << "\n";

    for(int i = 0; i < q; i++) {
        int ipt; cin >> ipt;
        cout << rst[ipt] << "\n";
    }
}