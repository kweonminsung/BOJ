#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string str;
    cin >> str;
    cout << str.at(0) << str.at(str.size() - 1) << "\n";
  }
}
