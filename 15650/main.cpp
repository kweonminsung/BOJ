#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  vector<int> arr;
  for (int i = 1; i <= n; i++)
    arr.push_back(i);

  vector<int> arr2;
  for (int i = 0; i < m; i++)
    arr2.push_back(1);
  for (int i = m; i < n; i++)
    arr2.push_back(0);

  do {
    for (int i = 0; i < n; i++) {
      if (arr2[i])
        cout << arr[i] << " ";
    }
    cout << "\n";
  } while (prev_permutation(arr2.begin(), arr2.end()));
}
