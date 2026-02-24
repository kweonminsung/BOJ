#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[5001];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int a, b, c;
    long long minN = LONG_LONG_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 2; j < n; j++){
            long long rst = arr[i] + arr[j];

            int mid = lower_bound(arr + i + 1, arr + j, -rst) - arr;
            int left = mid - 1;
            int right = upper_bound(arr + i + 1, arr + j, -rst) - arr;
            
            if(left > i && left < j) {
                if(abs(rst + arr[left]) < minN) {
                    minN = abs(rst + arr[left]);
                    a = arr[i];
                    b = arr[left];
                    c = arr[j];
                    // cout << "l" << i << " " << left << " " << j << "|" << a << " " << b << " " << c << "\n";
                }
            }
            if(mid > i && mid < j) {
                if(abs(rst + arr[mid]) < minN) {
                    minN = abs(rst + arr[mid]);
                    a = arr[i];
                    b = arr[mid];
                    c = arr[j];
                    // cout << "m" << i << " " << mid << " " << j << "|" << a << " " << b << " " << c << "\n";
                }
            }
            if(right > i && right < j) {
                if(abs(rst + arr[right]) < minN) {
                    minN = abs(rst + arr[right]);
                    a = arr[i];
                    b = arr[right];
                    c = arr[j];
                    // cout << "r" << i << " " << right << " " << j << "|" << a << " " << b << " " << c << "\n";
                }
            }

        }
    }

    cout << a << " " << b << " " << c;
}