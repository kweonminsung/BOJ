#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
using ll = long long;

int N, M, K;
ll a, b, c;
ll arr[MAX], tree[4 * MAX];

ll init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, n * 2) + init(mid + 1, end, n * 2 + 1);
}

void update(int start, int end, int n, int index, ll diff) {
  if (index > end || index < start)
    return;

  tree[n] += diff;
  if (start == end)
    return;
  int mid = (start + end) / 2;
  update(start, mid, 2 * n, index, diff);
  update(mid + 1, end, 2 * n + 1, index, diff);
}

ll sum(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 0;
  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return sum(start, mid, 2 * n, left, right) +
         sum(mid + 1, end, 2 * n + 1, left, right);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  init(0, N - 1, 1);

  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      update(0, N - 1, 1, b - 1, c - arr[b - 1]);
      arr[b - 1] = c;
    } else {
      cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
    }
  }
}
