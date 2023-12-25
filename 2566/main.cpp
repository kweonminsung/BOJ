#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num = 0, x, y;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int temp;
      cin >> temp;
      if (temp >= num) {
        num = temp;
        y = i + 1;
        x = j + 1;
      }
    }
  }

  cout << num << "\n" << y << " " << x;
}
