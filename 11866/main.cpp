#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;

    list<int> L;
    for(int i = 1; i <= N; i++) L.push_back(i);

    auto cursor = L.begin();
    advance(cursor, K - 1);

    cout <<  "<" << *cursor;
    cursor = L.erase(cursor);
    cursor--;

    while(!L.empty()) {
        int temp = K;
        while(temp--) {
            cursor++;
            if(cursor == L.end()) cursor = L.begin();
        }

        cout <<  ", " << *cursor;
        cursor = L.erase(cursor);
        cursor--;
    }

    cout << ">";
}
