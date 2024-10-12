#include <bits/stdc++.h>
#define MAX 500001

using namespace std;

int N, M, a, b, c, d;
int arr[MAX], tree[4 * MAX], lazy[4 * MAX];

int init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, 2 * n) ^ init(mid + 1, end, 2 * n + 1);
}

void updateLazy(int start, int end, int n) {
  if (lazy[n] != 0) {
    tree[n] = ((end - start + 1) % 2 == 0) ? tree[n] : tree[n] ^ lazy[n];
    if (start != end) {
      lazy[2 * n] ^= lazy[n];
      lazy[2 * n + 1] ^= lazy[n];
    }
    lazy[n] = 0;
  }
}

void update(int start, int end, int n, int left, int right, int value) {
  updateLazy(start, end, n);
  if (left > end || right < start)
    return;
  if (left <= start && end <= right) {
    tree[n] = ((end - start + 1) % 2 == 0) ? tree[n] : tree[n] ^ value;
    if (start != end) {
      lazy[2 * n] ^= value;
      lazy[2 * n + 1] ^= value;
    }
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, 2 * n, left, right, value);
  update(mid + 1, end, 2 * n + 1, left, right, value);
  tree[n] = tree[2 * n] ^ tree[2 * n + 1];
}

int query(int start, int end, int n, int index) {
  updateLazy(start, end, n);
  if (index > end || index < start)
    return 0;
  if (start == end)
    return tree[n];

  int mid = (start + end) / 2;
  return query(start, mid, 2 * n, index) ^
         query(mid + 1, end, 2 * n + 1, index);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  init(0, N - 1, 1);

  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      update(0, N - 1, 1, b, c, d);
    } else {
      cin >> b;
      cout << query(0, N - 1, 1, b) << "\n";
    }
  }
}
