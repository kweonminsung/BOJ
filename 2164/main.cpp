#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    queue<int> Q;
    for(int i = 1; i <= N; i++) Q.push(i);

    int index = 0;

    while(Q.size() > 1) {
        if(index % 2 == 1) Q.push(Q.front());
        Q.pop();
        index++;
    }

    cout << Q.front();
}
