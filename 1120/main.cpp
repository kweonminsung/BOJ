#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;

    int minN = a.length();

    for(int i = 0; i <= b.length() - a.length(); i++) {
        int diff = 0;
        for(int j = 0; j < a.length(); j++) {
            if(a[j] != b[i + j]) diff++;
        }
        minN = min(minN, diff);
    }

    cout << minN;
}