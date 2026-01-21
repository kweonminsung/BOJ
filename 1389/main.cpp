#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> edge[101];
int dist[101][101];
int rst[101];

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int ipt1, ipt2;
        cin >> ipt1 >> ipt2;

        edge[ipt1 - 1].push_back(ipt2 - 1);
        edge[ipt2 - 1].push_back(ipt1 - 1);
    }

    for(int i = 0; i < n; i++) {
        queue<int> Q;
        Q.push(i);
        dist[i][i] = 0;

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for(int nx : edge[cur]) {
                if(nx == i) continue;

                int newDist = dist[i][cur] + 1;

                if(dist[i][nx] != 0 && newDist >= dist[i][nx]) continue;
                dist[i][nx] = newDist;
                Q.push(nx);
            }
        }

        for(int j = 0; j < n; j++) {
            rst[i] += dist[i][j];
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++)
    //         cout << dist[i][j] << " ";
    //     cout << "\n";
    // }
        
    // for(int i = 0; i < n; i++)
    //     cout << rst[i] << " ";
    // cout << "\n";
    
    int ansI = 0, ansN = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        if(ansN >= rst[i]) {
            ansI = i + 1;
            ansN = rst[i];
        }
    }

    cout << ansI;
}