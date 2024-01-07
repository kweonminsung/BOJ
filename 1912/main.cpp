#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int arr[100000], M[100000];

  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr[i] = input;
  }

  int maxN = arr[0];
  M[0] = arr[0];

  for (int i = 1; i < n; ++i) {
    M[i] = max(M[i - 1] + arr[i], arr[i]);
    maxN = max(M[i], maxN);
  }
  cout << maxN;
}
