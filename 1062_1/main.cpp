#include <bits/stdc++.h>

using namespace std;

int n, k;
bool allUsed[27];

bool used[51][27];
int use[51];


int main() {
    cin >> n >> k;

    if(k < 5) {
        cout << "0";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
         
        for(char c: str) {
            if(!(c == 'a' || c == 'n' || c == 't' || c == 'c' || c == 'i')) {
                if(!used[i][c - 'a']) use[i]++;
                used[i][c - 'a'] = true;
                allUsed[c - 'a'] = true;
            }
        }
    }

    // for(int i = 0; i < n; i++)
    //     cout << use[i] << " ";

    
    vector<int> allUsedV;
    for(int i = 0; i < 27; i++)
        if(allUsed[i]) allUsedV.push_back(i);

    vector<int> permutV;
    for(int i = 0; i < allUsedV.size() - (k - 5); i++) permutV.push_back(0);
    for(int i = 0; i < k - 5; i++) permutV.push_back(1);
    // for(auto x : permutV)
    //     cout << x << " ";

    int rst = 0;
    do {
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            int toKill = use[i];

            for(int j = 0; j < permutV.size(); j++) {
                if(permutV[j] && used[i][allUsedV[j]]) toKill--;
            }

            if(toKill == 0) tmp++;
        }

        rst = max(rst, tmp);
    } while(next_permutation(permutV.begin(), permutV.end()));
    
    cout << rst;
}