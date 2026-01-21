#include <bits/stdc++.h>

using namespace std;

int t;
bool vis[10000];
int parent[10000];
char op[10000];

int D(int num) {
    return (num * 2) % 10000;
}
int S(int num) {
    if(num == 0) return 9999;
    return num - 1;
}
int L(int num) {
    return (num * 10) % 10000 + (num / 1000);
}
int R(int num) {
    return (num / 10) + (num % 10) * 1000;
}
int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        int from, to;
        cin >> from >> to;

        fill(vis, vis + 10000, false);
        fill(parent, parent + 10000, 0);
        fill(op, op + 10000, 0);

        queue<int> Q;
        Q.push(from);
        vis[from] = true;

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            if(cur == to) break;

            int next_num = D(cur);
            if(!vis[next_num]) {
                vis[next_num] = true;
                parent[next_num] = cur;
                op[next_num] = 'D';
                Q.push(next_num);
            }
            next_num = S(cur);
            if(!vis[next_num]) {
                vis[next_num] = true;
                parent[next_num] = cur;
                op[next_num] = 'S';
                Q.push(next_num);
            }
            next_num = L(cur);
            if(!vis[next_num]) {
                vis[next_num] = true;
                parent[next_num] = cur;
                op[next_num] = 'L';
                Q.push(next_num);
            }
            next_num = R(cur);
            if(!vis[next_num]) {
                vis[next_num] = true;
                parent[next_num] = cur;
                op[next_num] = 'R';
                Q.push(next_num);
            }
        }

        vector<char> rst;
        int x = to;
        while(x != from) {
            rst.push_back(op[x]);
            x = parent[x];
        }
        reverse(rst.begin(), rst.end());
        
        for(auto c : rst)
            cout << c;
        cout << "\n";
    }
}