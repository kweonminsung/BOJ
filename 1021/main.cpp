#include <bits/stdc++.h>

using namespace std;

int n, m;
int rst = 0;

vector<int> order;
deque<int> D;

void one() {
    D.pop_front();
}
void two() {
    D.push_back(D.front());
    D.pop_front();
    rst++;
}
void three() {
    D.push_front(D.back());
    D.pop_back();
    rst++;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int ipt;
        cin >> ipt;
        order.push_back(ipt);
    }

    for(int i = 1; i <= n; i++) {
        D.push_back(i);
    }

    for(int x : order) {
        int index = find(D.begin(), D.end(), x) - D.begin();

        if(index > D.size() / 2) {
            int cnt = D.size() - index;
            while(cnt--) {
                three();
            }
        } else {
            int cnt = index;
            while(cnt--) {
                two();
            }
        }
        one();
    }

    cout << rst;
}