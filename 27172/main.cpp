#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
vector<int> V;
int rst[1000001];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        V.push_back(arr[i]);
    }

    sort(V.begin(), V.end());

    for(int i = 0; i < n; i++) {
        for (int d = 1; d * d <= arr[i]; d++) {
            if(arr[i] % d == 0) {
                if(binary_search(V.begin(), V.end(), d)) {
                    rst[d]++;
                    rst[arr[i]]--;
                }
                if(d * d != arr[i] && binary_search(V.begin(), V.end(), arr[i] / d)) {
                    rst[arr[i] / d]++;
                    rst[arr[i]]--;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << rst[arr[i]] << " ";
    }
}