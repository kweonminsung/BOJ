#include <bits/stdc++.h>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num == 1) return false;

    int temp = sqrt(num);
    bool result = true;
    for(int i = 2; i <= temp; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;

    while(n != 0) {
        int tot = 0;
        for(int i = n + 1; i <= 2 * n; i++)
            if(isPrime(i)) tot++;

        cout << tot << "\n";

        cin >> n;
    }
}
