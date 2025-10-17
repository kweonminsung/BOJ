#include <bits/stdc++.h>

using namespace std;

int n, x;
int arr[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> x;

  sort(arr, arr + n);

  int start = 0, end = n - 1, rst = 0;

  while(start < end && start < n && end < n) {
    int v = arr[start] + arr[end];

    if(v > x) end--;
    else if(v == x) {
      start++;
      end--;
      rst++;
    } else start++;
  }

  cout << rst;
}
