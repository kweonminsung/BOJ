#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long arr[1000001];

int main() {
    cin >> n >> m;

    long long shit = 0;

    for(long long i = 0; i < n; i++) {
        long long input;
        cin >> input;
        arr[i] = input;
        shit = max(shit, input);
    }

    long long left = 0, right = shit;
    long long ans = -1;

    while(left <= right) {
        // cout << left << "|" << right << "\n";
        long long sum = 0;
        long long mid = (left + right) / 2;

        for(long long i = 0; i < n; i++) {
            sum += (mid <= arr[i] ? arr[i] - mid : 0);
        }

        if(sum >= m) {
            left = mid + 1;
            ans = mid;
        }
        else right = mid - 1;
    }
    
    cout << ans;
}