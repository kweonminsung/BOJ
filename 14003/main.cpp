#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> lis;
int arr[1000001];
int pre[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(pre, pre + n, -1);

    int lastAppendCur = 0;

    for(int i = 0; i < n; i++) {
        int ipt;
        cin >> ipt;
        arr[i] = ipt;

        if(lis.empty()) {
            lis.push_back({ipt, i});
        } else {
            if(lis.back().first < ipt) {
                pre[i] = lis.back().second;
                lis.push_back({ipt, i});
                lastAppendCur = i;
            } else {
                int index = lower_bound(lis.begin(), lis.end(), ipt, [](const pair<int,int>& a, int value) {
                    return a.first < value;
                }) - lis.begin();
                if(index != 0) {
                    pre[i] = lis[index - 1].second;
                }
                lis[index] = {ipt, i};
            }
        }
    }
    cout << lis.size() << "\n";

    int cur = lastAppendCur;
    vector<int> rst;
    while(cur != -1) {
        rst.push_back(arr[cur]);
        cur = pre[cur];
    }

    reverse(rst.begin(), rst.end());

    for(auto x : rst) {
        cout << x << " ";
    }
}