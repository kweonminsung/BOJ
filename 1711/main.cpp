#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> V;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }

    int rst = 0;
   
    for(int aI = 0; aI < n; aI++) {
        for(int bI = aI + 1; bI < n; bI++) {
            for(int cI = bI + 1; cI < n; cI++) {
                long long a = ((long long)V[aI].first - V[bI].first) * ((long long)V[aI].first - V[bI].first) + ((long long)V[aI].second - V[bI].second) * ((long long)V[aI].second - V[bI].second);
                long long b = ((long long)V[bI].first - V[cI].first) * ((long long)V[bI].first - V[cI].first) + ((long long)V[bI].second - V[cI].second) * ((long long)V[bI].second - V[cI].second);
                long long c = ((long long)V[aI].first - V[cI].first) * ((long long)V[aI].first - V[cI].first) + ((long long)V[aI].second - V[cI].second) * ((long long)V[aI].second - V[cI].second);
                
                if(a + b == c || a + c == b || b + c == a) { rst++; }
            }
        }
    }

    cout << rst;
}