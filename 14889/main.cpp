#include <bits/stdc++.h>

using namespace std;

int n, minN = INT_MAX;
bool isused[20];
int points[20][20];

void func(int k, int idx) {
  if (k == n / 2) {
    int tempS = 0, tempL = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isused[i] && isused[j])
          tempS += points[i][j];
        if (!isused[i] && !isused[j])
          tempL += points[i][j];
      }
    }
    minN = min(minN, tempS > tempL ? tempS - tempL : tempL - tempS);
    return;
  }

  for (int i = idx; i < n; i++) {
    isused[i] = true;
    func(k + 1, i + 1);
    isused[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> points[i][j];
    }
  }

  func(0, 0);

  cout << minN;
}
