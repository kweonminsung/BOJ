#include <bits/stdc++.h>

using namespace std;

string a, b, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> c;

  cout << (stoi(a) + stoi(b) - stoi(c)) << "\n" << stoi(a + b) - stoi(c);
}
