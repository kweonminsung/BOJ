#include <bits/stdc++.h>

using namespace std;

bool checkInclude(int num) {
    int temp = 0; bool flag = false;
    vector<int> v;
    while(num) {
        v.push_back(num % 10);
        num /= 10;
    }

    for(auto i : v) {
        if(!flag && i == 6) {
            flag = true;
            temp++;
            continue;
        }
        if(flag && i == 6) {
            temp++;
            if(temp == 3) return true;
            continue;
        }
        flag = false;
        temp = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int t = 666;

    while(true) {
        if(checkInclude(t)) {
            n--;
            if(n == 0) break;
        }

        t++;
    }

    cout << t;
}
