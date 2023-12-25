#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, int> j;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    j[input]++;
  }

  int m;
  cin >> m;
  while (m--) {
    int input;
    cin >> input;
    cout << j[input] << " ";
  }
}
