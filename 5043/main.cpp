#include <bits/stdc++.h>

using namespace std;

long long n, b;

int main() {
    cin >> n >> b;

    if(pow(2, b + 1) > n) cout << "yes";
    else cout << "no";
}