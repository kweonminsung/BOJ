#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int input[10];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << input[arr[i]] << " ";
    cout << "\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    arr[k] = i;
    func(k + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> input[i];

  sort(input + 1, input + n + 1);
  func(0);
}
