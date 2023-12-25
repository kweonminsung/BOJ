#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char arr[5][20] = {0};

  for (int i = 0, j = 0; i < 5; i++) {
    j = 0;
    string str;
    cin >> str;
    for (char c : str) {
      arr[i][j] = c;
      j++;
    }
  }

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 5; j++) {
      if (arr[j][i])
        cout << arr[j][i];
    }
  }
}
