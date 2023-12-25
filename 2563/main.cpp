#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int total = 0;
  int arr[100][100] = {0};

  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i < x + 10; i++) {
      for (int j = y; j < y + 10; j++) {
        if (arr[i][j] == 0) {
          arr[i][j] = 1;
          total++;
        }
      }
    }
  }

  cout << total;
}
