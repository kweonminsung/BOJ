#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 28;
  int arr[30] = {
      0,
  };

  while (n--) {
    int k;
    cin >> k;
    arr[k - 1] = 1;
  }

  for (int i = 0; i < 30; i++) {
    if (arr[i] == 0)
      cout << i + 1 << "\n";
  }
}
