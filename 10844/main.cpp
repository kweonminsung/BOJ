#include <bits/stdc++.h>
#define NUM 1000000000

using namespace std;
using ll = long long;

int n;
int arr[101][10];

int func(int k) {
  if (k == 1)
    return 9;

  func(k - 1);

  ll total = 0;
  for (int i = 0; i <= 9; i++) {
    if (i == 0)
      arr[k][i] = arr[k - 1][i + 1];
    else if (i == 9)
      arr[k][i] = arr[k - 1][i - 1];
    else
      arr[k][i] = (arr[k - 1][i - 1] + arr[k - 1][i + 1]) % NUM;

    total += arr[k][i] % NUM;
  }
  return total % NUM;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  fill(arr[1], arr[1] + 10, 1);
  arr[1][0] = 0;

  cout << func(n);
}