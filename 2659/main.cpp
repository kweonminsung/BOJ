#include <bits/stdc++.h>

using namespace std;

int arr[4];
set<int> S;


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = min({
        1000 * a + 100 * b + 10 * c + d,
        1000 * b + 100 * c + 10 * d + a,
        1000 * c + 100 * d + 10 * a + b,
        1000 * d + 100 * a + 10 * b + c
    });
    
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {
                for(int m = 1; m <= 9; m++) {
                    S.insert(min({
                        1000 * i + 100 * j + 10 * k + m,
                        1000 * j + 100 * k + 10 * m + i,
                        1000 * k + 100 * m + 10 * i + j,
                        1000 * m + 100 * i + 10 * i + k
                    }));
                }
            }
        }
    }

    vector<int> V(S.begin(), S.end());

    // for(auto x : V) {
    //     cout << x << " ";
    // }

    cout << find(V.begin(), V.end(), n) - V.begin() + 1;
}