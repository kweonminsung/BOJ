#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[8];
    int state;

    for(int i = 0; i < 8; i++) cin >> arr[i];
    
    if(arr[0] == 1) state = 1;
    else if(arr[0] == 8) state = -1;

    for(int i = 0; i < 7; i++) {
        if(state == 1) {
            if(arr[i] > arr[i + 1]) {
                cout << "mixed";
                return 0;
            }

        } else {
            if(arr[i] < arr[i + 1]) {
                cout << "mixed";
                return 0;
            }
        }
    }
    cout << (state == 1 ? "ascending" : "descending");
}
