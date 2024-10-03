#include <bits/stdc++.h>

using namespace std;

int N, K, cnt = 0, result = 0;
int arr[500001], tmp[500001];

void merge_(int p, int q, int r) {
  int i = p, j = q + 1, t = 1;

  while (i <= q && j <= r) {
    if (arr[i] <= arr[j])
      tmp[t++] = arr[i++];
    else
      tmp[t++] = arr[j++];
  }
  while (i <= q)
    tmp[t++] = arr[i++];
  while (j <= r)
    tmp[t++] = arr[j++];
  i = p;
  t = 1;
  while (i <= r) {
    cnt++;
    if (cnt == K)
      result = tmp[t];
    arr[i++] = tmp[t++];
  }
}

void merge_sort(int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge_(p, q, r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  merge_sort(0, N - 1);

  cout << (cnt < K ? -1 : result);
}
