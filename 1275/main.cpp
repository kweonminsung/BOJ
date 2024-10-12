#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
using ll = long long;

ll N, Q, a, b, c, d;
ll arr[MAX], arrIndex[MAX], tree[4 * MAX];

ll init(int start, int end, int n) {
  if (start == end) {
    arrIndex[start] = n;
    return tree[n] = arr[start];
  }

  int mid = (start + end) / 2;
  return tree[n] = init(start, mid, 2 * n) + init(mid + 1, end, 2 * n + 1);
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

void update(int index, int value) {
  int cur = arrIndex[index];

  tree[cur] = value;
  while (cur != 1) {
    tree[cur / 2] = tree[cur] + tree[(cur % 2 == 0) ? (cur + 1) : (cur - 1)];
    cur /= 2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  init(0, N - 1, 1);

  for (int i = 0; i < Q; i++) {
    cin >> a >> b >> c >> d;
    cout << sum(0, N - 1, 1, (a < b ? a : b) - 1, (a > b ? a : b) - 1) << "\n";
    arr[c - 1] = d;
    update(c - 1, d);
  }
}
