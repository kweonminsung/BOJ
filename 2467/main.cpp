#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;

    int minN = INT_MAX; 
    int rst[2] = {0, 0};

    while(start < end) {
        int tot = arr[start] + arr[end];

        if(abs(tot) < minN) {
            minN = abs(tot);
            rst[0] = arr[start];
            rst[1] = arr[end];
        }

        if(tot < 0) {
            start++;
        } else {
            end--;
        }
    }

    cout << rst[0] << " " << rst[1];
}