#include <bits/stdc++.h>

using namespace std;

int t, n, k, x, y, w;
vector<int> edge[1001];
vector<int> edge_r[1001];
int depend[1001];
int tmb[1001];
int dptmb[1001];

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        fill(tmb, tmb + n, 0);
        fill(dptmb, dptmb + n, 0);
        fill(depend, depend + n, 0);
        for(int j = 1; j <= n; j++) {
            edge[j].clear();
            edge_r[j].clear();
        }

        for(int j = 1; j <= n; j++)
            cin >> tmb[j];

        for(int j = 1; j <= k; j++) {
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge_r[b].push_back(a);
            depend[b]++;
        }

        cin >> w;

        queue<int> Q;
        for(int j = 1; j <= n; j++) {
            if(depend[j] == 0) Q.push(j);
        }

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            int lngestT = 0;
            for(auto x : edge_r[cur]) {
                lngestT = max(lngestT, dptmb[x]);
            }
            dptmb[cur] = lngestT + tmb[cur];

            for(auto x : edge[cur]) {
                depend[x]--;
                if(depend[x] == 0) Q.push(x);
            }
        }

        cout << dptmb[w] << "\n";
    }
    
}