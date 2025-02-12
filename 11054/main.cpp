#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int N, ans = 0;
int arr[MAX], dpasc[MAX], dpdesc[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  fill(dpasc, dpasc + MAX, 1);
  fill(dpdesc, dpdesc + MAX, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j])
        dpasc[i] = max(dpasc[i], dpasc[j] + 1);
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = N - 1; j > i; j--) {
      if (arr[i] > arr[j])
        dpdesc[i] = max(dpdesc[i], dpdesc[j] + 1);
    }
  }

  for (int i = 0; i < N; i++) {
    ans = max(ans, dpasc[i] + dpdesc[i] - 1);
  }
  cout << ans;
}