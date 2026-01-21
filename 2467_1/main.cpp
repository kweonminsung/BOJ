#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int minN = INT_MAX;
    int rst[2] = {0, 0};

    for(int start = 0; start < n - 1; start++) {
        int target = -arr[start];
        int end = lower_bound(arr + start + 1, arr + n, target) - arr;

        // Check the found element (idx) and the one before it (idx-1)
        for(int j = 0; j < 2; j++) {
            int current_idx = end - j;
            
            if(current_idx >= n || current_idx <= start) continue;

            int tot = abs(arr[start] + arr[current_idx]);
            if(tot < minN) {
                minN = tot;
                rst[0] = arr[start];
                rst[1] = arr[current_idx];
            }
        }
    }

    cout << rst[0] << " " << rst[1];
}