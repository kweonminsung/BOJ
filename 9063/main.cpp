#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> v1, v2;
    
    while(n--) {
        int t1, t2; cin >> t1 >> t2;
        v1.push_back(t1);
        v2.push_back(t2);
    }
    
    cout << (*max_element(v1.begin(), v1.end()) - *min_element(v1.begin(), v1.end())) * (*max_element(v2.begin(), v2.end()) - *min_element(v2.begin(), v2.end()));
}
