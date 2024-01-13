#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
set<int> S;
int numLeft[10001];

void func(int k) {
  if (k == m) {
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for (int s : S) {
    if (numLeft[s] != 0) {
      arr[k] = s;
      numLeft[s]--;
      func(k + 1);
      numLeft[s]++;
    }
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
    numLeft[input]++;
  }

  func(0);
}
