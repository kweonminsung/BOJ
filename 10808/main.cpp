#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    int arr[26] = {};

    for(auto c : s)
        arr[c - 'a']++;

    for(char i = 0; i < 26; i++)
        cout << arr[i] << " ";
}
