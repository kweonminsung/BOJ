#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int N, M, a, b, c;
int tree[4 * MAX], lazy[4 * MAX];

void updateLazy(int start, int end, int n) {
  if (lazy[n] != 0) {
    tree[n] = (end - start + 1) - tree[n];
    if (start != end) {
      lazy[2 * n] = !lazy[2 * n];
      lazy[2 * n + 1] = !lazy[2 * n + 1];
    }
    lazy[n] = 0;
  }
}

void update(int start, int end, int n, int left, int right) {
  updateLazy(start, end, n);
  if (left > end || right < start)
    return;
  if (left <= start && end <= right) {
    tree[n] = (end - start + 1) - tree[n];
    if (start != end) {
      lazy[2 * n] = !lazy[2 * n];
      lazy[2 * n + 1] = !lazy[2 * n + 1];
    }
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, 2 * n, left, right);
  update(mid + 1, end, 2 * n + 1, left, right);
  tree[n] = tree[2 * n] + tree[2 * n + 1];
}

int sum(int start, int end, int n, int left, int right) {
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

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    if (a == 0) {
      update(0, N - 1, 1, b - 1, c - 1);
    } else {
      cout << sum(0, N - 1, 1, b - 1, c - 1) << "\n";
    }
  }
}
