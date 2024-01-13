#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
set<int> S;

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int s : S) {
    arr[k] = s;
    func(k + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    int input;
    cin >> input;
    S.insert(input);
  }

  func(0);
}
