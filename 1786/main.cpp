#include <bits/stdc++.h>

using namespace std;
int oV[1000001];

int main() {
    string t, p;

    getline(cin, t);
    getline(cin, p);

    // j에 따른 k 미리 계산    
    oV[0] = 0;
    for(int i = 1; i < p.length(); i++) {
        int k = oV[i - 1];

        while(k > 0 && p[i] != p[k]) {
            k = oV[k - 1];
        }

        if(p[i] == p[k]) {
            k++;
        }
        oV[i] = k;
    }

    // for(int i = 0; i < p.length(); i++) cout << oV[i] << " ";

    vector<int> V;
    int i = 0, j = 0;
    while (i < t.length()) {
        if (t[i] == p[j]) {
            i++;
            j++;

            if (j == p.length()) {
                V.push_back(i - j + 1);
                j = oV[j - 1];
            }
        } else {
            if (j > 0) {
                j = oV[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << V.size() << "\n";
    for(auto x : V) cout << x << " ";
}