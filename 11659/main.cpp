#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int arr[100001];
  cin >> arr[1];
  for (int i = 2; i <= n; i++) {
    int input;
    cin >> input;
    arr[i] = arr[i - 1] + input;
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    cout << arr[to] - arr[from - 1] << "\n";
  }
}
