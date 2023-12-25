#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, v, total = 0;
  int arr[100];
  cin >> n;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  cin >> v;

  for (int i = 0; i < n; i++) {
    if (arr[i] == v)
      total++;
  }

  cout << total;
}
