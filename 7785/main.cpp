#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<string> s;

  while (n--) {
    string input, command;
    cin >> input >> command;
    if (command == "enter") {
      s.insert(input);
    } else {
      s.erase(input);
    }
  }

  for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
    cout << *iter << "\n";
  }
}
