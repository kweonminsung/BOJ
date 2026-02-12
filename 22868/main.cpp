#include <bits/stdc++.h>

using namespace std;

int n, m, from, to;
vector<int> edge[10001];
int dist[10001];
int pre[10001];

bool cantGo[10001];
int dist2[10001];

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int ipt1, ipt2;
        cin >> ipt1 >> ipt2;
        edge[ipt1].push_back(ipt2);
        edge[ipt2].push_back(ipt1);
    }
    cin >> from >> to;

    for(int i = 1; i <= n; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    fill(dist, dist + n + 1, -1);
    dist[from] = 0;
    queue<int> Q1;
    Q1.push(from);

    while(!Q1.empty()) {
        int cur = Q1.front();
        Q1.pop();

        for(int nx : edge[cur]) {
            if(dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            pre[nx] = cur;

            Q1.push(nx);
        }
    }

    // for(int i = 0; i <= n; i++) {
    //     cout << pre[i] << " ";
    // }

    int cur = to;
    while(cur != from) {
        cantGo[cur] = true;
        cur = pre[cur];
    }

    cantGo[from] = cantGo[to] = false;

    fill(dist2, dist2 + n + 1, -1);
    dist2[to] = 0;
    queue<int> Q2;
    Q2.push(to);

    while(!Q2.empty()) {
        int cur = Q2.front();
        Q2.pop();

        for(int nx : edge[cur]) {
            if(cantGo[nx]) continue;
            if(dist2[nx] != -1) continue;
            dist2[nx] = dist2[cur] + 1;

            Q2.push(nx);
        }
    }

    // cout << dist[to] << " " << dist2[from] << "\n";
    cout << (dist[to] + dist2[from]);
}