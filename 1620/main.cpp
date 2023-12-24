#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<string> v;
  map<string, int> p;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    v.push_back(input);
    p.insert({input, i});
  }

  while (m--) {
    string input;
    cin >> input;
    if ('1' <= input[0] && input[0] <= '9') {
      cout << v[stoi(input) - 1];
    } else {
      cout << p[input] + 1;
    }
    cout << "\n";
  }
}
