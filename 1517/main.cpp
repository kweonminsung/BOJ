#include <bits/stdc++.h>
#define MAX 500001

using namespace std;
using ll = long long;

ll N, cnt = 0;
ll arr[MAX], tmp[MAX];

void merge_(ll p, ll q, ll r) {
  ll i = p, j = q + 1, t = 1;

  while (i <= q && j <= r) {
    if (arr[i] <= arr[j])
      tmp[t++] = arr[i++];
    else {
      tmp[t++] = arr[j++];
      cnt += (q - i) + 1;
    }
  }
  while (i <= q)
    tmp[t++] = arr[i++];
  while (j <= r)
    tmp[t++] = arr[j++];
  i = p;
  t = 1;
  while (i <= r) {
    arr[i++] = tmp[t++];
  }
}

void merge_sort(ll p, ll r) {
  if (p < r) {
    ll q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge_(p, q, r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  merge_sort(0, N - 1);

  cout << cnt;
}
