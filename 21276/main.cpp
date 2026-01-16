#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> names;
unordered_map<string, int> namesM;
vector<int> edge[1001];
vector<int> child[1001];
bool childTaken[1001];
int indeg[1001];

vector<int> greatFather;

bool cmp(int a, int b) { return names[a] < names[b]; }

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string ipt;
        cin >> ipt;
        
        names.push_back(ipt);
        namesM[ipt] = i;
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        string from, to;
        cin >> to >> from;

        edge[namesM[from]].push_back(namesM[to]);
        indeg[namesM[to]]++;
    }

    queue<int> Q;

    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) {
            Q.push(i);
            greatFather.push_back(i);
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int nxt: edge[cur]) {
            indeg[nxt]--;

            if (indeg[nxt] == 0) {
                if(!childTaken[nxt]) {
                    childTaken[nxt] = true;
                    child[cur].push_back(nxt);
                }
                Q.push(nxt);
            }
        }
    }

    sort(greatFather.begin(), greatFather.end(), cmp);
    cout << greatFather.size() << "\n";
    for(int x : greatFather) cout << names[x] << " ";
    cout << "\n";


    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), cmp);
    
    for (int x : order) {
        sort(child[x].begin(), child[x].end(), cmp);

        cout << names[x] << " " << child[x].size() << " ";
        for (int y : child[x])
        cout << names[y] << " ";
        cout << "\n";
    }
}