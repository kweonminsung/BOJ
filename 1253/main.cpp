#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2002];
bool able[2002];

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        int left = 0, right = n - 1;

        while(left < right) {
            if(left == i) {
                left++;
                continue;
            }
            if(right == i) {
                right--;
                continue;
            }

            long long sum = arr[left] + arr[right];

            if(sum == arr[i]) {
                able[i] = true;
                break;
            } else if(sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << count(able, able + n, true);
}