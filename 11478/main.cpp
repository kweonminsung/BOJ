#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;
  set<string> s;

  for (int i = 1; i <= str.size(); i++) {
    for (int j = 0; j < str.size() - i + 1; j++) {
      s.insert(str.substr(j, i));
    }
  }

  cout << s.size();
}
