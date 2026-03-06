#include <bits/stdc++.h>

using namespace std;

int n, c;
int arr[200001];
int diff[200000];

int main() {
    cin >> n >> c;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++) {
        diff[i] = arr[i + 1] - arr[i];
    }
    
    int left = *min_element(diff, diff + n - 1), right = accumulate(diff, diff + n - 1, 0), rst = left;
    while(left <= right) {
        int mid = (left + right) / 2;
        // cout << "\n" << mid << "|";

        bool yes = true; int cur = 0, curDiffI = 0, sum = 0;
        while(cur < c - 1) {
            while(sum < mid && curDiffI < n - 1) {
                sum += diff[curDiffI];
                // cout << sum << " ";
                curDiffI++;
            }
            
            if(sum < mid) {
                yes = false;
                break;
            }

            sum = 0;
            cur++;
        }
        if(cur != c - 1) yes = false;

        if(yes) {
            rst = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << rst;
}