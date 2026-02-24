#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;

int n;
int arr[300002];
long long prefixSum[300002];
long long powTwo[300002];
long long rst = 0;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i <= n / 2; i++) {
        if(i == 0) {
            prefixSum[i] = (arr[n - 1] - arr[0]) % DIV;
            continue;
        }
        prefixSum[i] = (prefixSum[i - 1] + (arr[n - 1 - i] - arr[i])) % DIV;
    }


    powTwo[0] = 1;
    for(int i = 1; i < n - 1; i++) {
        // cout << prefixSum[i] << " ";
        powTwo[i] = (2 * powTwo[i - 1]) % DIV;
    }

    for(int i = 0; i < n - 1; i++) {
        // cout << i << " " << pow(2, i) << " " << prefixSum[(i >  n / 2 ? n - 1 - i : i)] << "\n";
        rst = (rst + powTwo[i] * prefixSum[(i >  n / 2 ? n - 2 - i : i)]) % DIV;
    }

    cout << rst;
}