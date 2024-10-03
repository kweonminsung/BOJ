#include <bits/stdc++.h>
#define NUM 1000001
#define MOD 1000000007

using namespace std;
using ll = long long;

int N, M, K;
ll a, b, c;
ll arr[NUM], tree[4 * NUM];

ll init(int start, int end, int n) {
  if (start == end) {
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] =
             (init(start, mid, n * 2) * init(mid + 1, end, n * 2 + 1)) % MOD;
}

void update(int start, int end, int n, int index, ll value) {
  if (index > end || index < start)
    return;

  if (start == end) {
    tree[n] = value;
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, 2 * n, index, value);
  update(mid + 1, end, 2 * n + 1, index, value);
  tree[n] = (tree[n * 2] * tree[n * 2 + 1]) % MOD;
}

ll product(int start, int end, int n, int left, int right) {
  if (left > end || right < start)
    return 1;
  if (left <= start && end <= right)
    return tree[n];

  int mid = (start + end) / 2;
  return (product(start, mid, 2 * n, left, right) *
          product(mid + 1, end, 2 * n + 1, left, right)) %
         MOD;
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
      update(0, N - 1, 1, b - 1, c);
      arr[b - 1] = c;
    } else {
      cout << product(0, N - 1, 1, b - 1, c - 1) << "\n";
    }
  }
}
