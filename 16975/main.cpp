#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
using ll = long long;

int N, M, a, b, c, d;
ll arr[MAX], tree[4 * MAX];

void init(int start, int end, int n) {
  if (start == end) {
    tree[n] = arr[start];
    return;
  }

  int mid = (start + end) / 2;
  init(start, mid, 2 * n);
  init(mid + 1, end, 2 * n + 1);
}

void update(int start, int end, int n, int left, int right, ll diff) {
  if (left > end || right < start)
    return;
  if (left <= start && end <= right) {
    tree[n] += diff;
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, 2 * n, left, right, diff);
  update(mid + 1, end, 2 * n + 1, left, right, diff);
}

ll print(int start, int end, int n, int index) {
  if (start > index || index > end)
    return 0;
  if (start == end)
    return tree[n];

  int mid = (start + end) / 2;
  return print(start, mid, 2 * n, index) +
         print(mid + 1, end, 2 * n + 1, index) + tree[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  cin >> M;

  init(0, N - 1, 1);

  for (int i = 0; i < M; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      update(0, N - 1, 1, b - 1, c - 1, d);
    } else {
      cin >> b;
      cout << print(0, N - 1, 1, b - 1) << "\n";
    }
  }
}
