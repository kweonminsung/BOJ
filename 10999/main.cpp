#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
using ll = long long;

int N, M, K;
ll a, b, c, d;
ll arr[MAX], tree[4 * MAX], lazy[4 * MAX];

ll init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, 2 * n) + init(mid + 1, end, 2 * n + 1);
}

void updateLazy(int start, int end, int n) {
  if (lazy[n] != 0) {
    tree[n] += (end - start + 1) * lazy[n];
    if (start != end) {
      lazy[2 * n] += lazy[n];
      lazy[2 * n + 1] += lazy[n];
    }
    lazy[n] = 0;
  }
}

void update(int start, int end, int n, int left, int right, ll value) {
  updateLazy(start, end, n);
  if (left > end || right < start)
    return;
  if (left <= start && end <= right) {
    tree[n] += (end - start + 1) * value;
    if (start != end) {
      lazy[2 * n] += value;
      lazy[2 * n + 1] += value;
    }
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, 2 * n, left, right, value);
  update(mid + 1, end, 2 * n + 1, left, right, value);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
}

ll sum(int start, int end, int n, int left, int right) {
  updateLazy(start, end, n);
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
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      update(0, N - 1, 1, b - 1, c - 1, d);
    } else {
      cin >> b >> c;
      cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
    }
  }
}
