#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<int> s;

  while (n--) {
    int input;
    cin >> input;
    s.insert(input);
  }

  for (auto i : s)
    cout << i << "\n";
}
