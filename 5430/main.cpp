#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        string op;
        cin >> op;

        int n;
        cin >> n;
        string arrstr;
        cin >> arrstr;
        vector<int> V;
        istringstream iss(arrstr.substr(1, arrstr.length() - 2));

        string tmp;
        while(getline(iss, tmp, ',')) {
            V.push_back(stoi(tmp));
        }

        int start = 0, end = V.size() - 1;
        bool reversed = false;
        
        bool breaked = false;
        for(char c : op) {
            if(c == 'R') {
                reversed = !reversed;
            } else {
                if(start > end) {
                    breaked = true;
                    break;
                }

                if(!reversed)
                    start++;
                else
                    end--;
            }
        }

        if(breaked) {
            cout << "error\n";
            continue;
        }
        // cout << start << " " << end << "\n";
        cout << "[";
        if(start <= end) {
            if(!reversed) {
                for(int j = start; j <= end; j++) {
                    cout << V[j];
                    if(j != end) cout << ",";
                }
            } else {
                for(int j = end; j >= start; j--) {
                    cout << V[j];
                    if(j != start) cout << ",";
                }
            }
        }
        cout << "]\n";
    }
}