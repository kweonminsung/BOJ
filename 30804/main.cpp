#include <bits/stdc++.h>

using namespace std;

int n;
int arr[200001];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(n == 1) {
        cout << 1;
        return 0;
    }

    int rst = 2, maxRst = 2;
    int left = 0, right = 1;
    int cnt = (arr[0] != arr[1] ? 2 : 1);
    unordered_map<int, int> M;
    M[arr[0]]++;
    M[arr[1]]++;
    
    while(right <= n - 2) {
        // cout << left << " " << right << " " << cnt << "\n";
        if(M[arr[right + 1]] == 0 && cnt == 2) {
            M[arr[left]]--;
            if(M[arr[left]] == 0) {
                cnt--;
            }
            left++;
            if(left > right) right++;
            rst--;
        } else {
            if(M[arr[right + 1]] == 0) {
                cnt++;
            }
            right++;
            M[arr[right]]++;
            rst++;
            maxRst = max(maxRst, rst);
        }
    }

    cout << maxRst;
}