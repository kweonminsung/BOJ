#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101];
bool inited[101];

int main() {
    cin >> n;

    int tot = 0;
    for(int i = 0; i < n; i++) {
        int cow, loc;
        cin >> cow >> loc;
        
        if(!inited[cow]) {
            inited[cow] = true;
            arr[cow] = loc;
        } else {
            if(arr[cow] != loc) {
                tot++;
            }
            arr[cow] = loc;
        }
    }
    cout << tot;
}