#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[100001];

int main() {
    cin >> n >> k;

    for(int i = 0 ; i < n; i++)
        cin >> arr[i];

    int start = 0;
    int maxN = 0, prev = 0;
    for(int i = 0; i < k; i++)
        maxN += arr[i];
    prev = maxN;

    for(start = 1; start < n - k + 1; start++) {
        // cout << prev << " ";
        int tmp = prev - arr[start - 1] + arr[start + k - 1];

        if(tmp > maxN) maxN = tmp;
        prev = tmp;
    }

    cout << maxN;
}