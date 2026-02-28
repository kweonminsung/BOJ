#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> edge[1001];
int dist[1001];

int travel(int from, int to) {
    // cout << from << " " << to << "\n";
    fill(dist, dist + 1001, -1);

    queue<int> Q;
    Q.push(from);
    dist[from] = 0;

    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        
        if(cur == to) break;

        for(auto nx : edge[cur]) {
            if(dist[nx.first] != -1) continue;

            dist[nx.first] = dist[cur] + nx.second;
            // cout << nx.first << " " << dist[nx.first] << "\n";
            Q.push(nx.first);
        }
    }

    return dist[to];
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n - 1; i++) {
        int from, to, d;
        cin >> from >> to >> d;
        edge[from].push_back({to, d});
        edge[to].push_back({from, d});
    }

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        cout << travel(from, to) << "\n";
    }
}