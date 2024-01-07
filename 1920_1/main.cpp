#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  vector<int> V;

  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    V.push_back(input);
  }

  sort(V.begin(), V.end());

  cin >> m;
  while (m--) {
    int input;
    cin >> input;

    cout << (binary_search(V.begin(), V.end(), input) ? "1\n" : "0\n");
  }
}
