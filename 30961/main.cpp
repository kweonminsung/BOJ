#include <bits/stdc++.h>

using namespace std;

long n;
long arr[1000001];

int main() {
    cin >> n;

    for(long i = 0; i < n; i++)
    cin >> arr[i];
    
    sort(arr, arr + n);
    long rst = 0;
    for(long i = 0; i < n; i++)
        rst ^= (arr[i] * arr[i]);
    for(long i = 0; i < n - 1; i++)
        rst ^= (arr[i] * arr[i + 1]);
    
    cout << rst;
}