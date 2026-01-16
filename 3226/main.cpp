#include <bits/stdc++.h>

using namespace std;

int n, tot;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
    
        int hh, mm, dd;
    
        string tmp;
        istringstream iss(str);
        getline(iss, tmp, ':');
        hh = stoi(tmp);
        getline(iss, tmp, ':');
        mm = stoi(tmp);
        
        cin >> dd;

        if(hh >= 7 && hh <= 18) {
            if(hh == 18 && mm + dd > 60) {
                tot += 10 * (60 - mm) + 5 * (dd - 60 + mm);
            } else {
                tot += 10 * dd;
            }
        } else {
            if(hh == 6 && mm + dd > 60) {
                tot += 5 * (60 - mm) + 10 * (dd - 60 + mm);
            } else {
                tot += 5 * dd;
            }
        }
    }
    cout << tot;
}